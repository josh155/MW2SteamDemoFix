// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <Windows.h>
#include "detours.h"
#include "Hooks.h"
#include "MapBytes.h"
#include "Functions.h"
#define MAX_MSGLEN 4000
CallHook gamestateWriteHook;
CallHook recordGamestate;
StompHook baselineStoreHook;
StompHook baselineToFile;

DWORD gamestateWriteHookLoc = 0x4C3216;

void GamestateWriteHookFunc(msg_t* msg, char byte) {

	MSG_WriteLong(msg, 0);
	MSG_WriteByte(msg, byte);
}

void __declspec(naked) GamestateWriteHookStub() {
	__asm jmp GamestateWriteHookFunc
}



DWORD baselineStoreHookLoc = 0x004CA057;//We need to hook further back than what FourDeltaOne did because we don't have enough room
DWORD baselineStoreHookRet = 0x4CA0C5;

char baselineSnap[131072];
PBYTE bssMsg = 0;

int bssMsgOff = 0;
int bssMsgLen = 0;
DWORD message1 = 0xBCCB68;
DWORD message2 = 0xAF5FF4;
void __declspec(naked)BaselineStoreHookFunc() {

	_asm {
		MOV DWORD PTR DS : [message2] , EBP 
		mov bssMsg, edi

	}

	bssMsgLen = *(int*)(bssMsg + 20);
	bssMsgOff = *(int*)(bssMsg + 28);
	memcpy(baselineSnap, (void*) * ((DWORD*)(bssMsg + 8)), *(DWORD*)(bssMsg + 20));
	//printf("baselineSnap: %p \n", &baselineSnap); //Print the address of baselineSnap
	//printf("baseline Length: %d \n", bssMsgLen);//Print the size of baselineSnap
	//printf("baseline Offset: %d \n", bssMsgOff);//Print the size of commands length of baselinesnap
	__asm
	{

		jmp baselineStoreHookRet
	}
}

int* demoFile = (int*)0xAF5FFC;
int* serverMessageSequence = (int*)0xAD5F94;
char byte0 = 0;

DWORD baselineToFileLoc = 0x4C34D0;
DWORD baselineToFileRet = 0x4C34DA;

void WriteBaseline() {
	msg_t buf;
	static char bufData[131072];
	static char cmpData[65535];
	int byte8 = 8;

	MSG_Init(&buf, bufData, 131072);
	MSG_WriteData(&buf, &baseline[0], 1224);//For some reason 1.2.211 needs this as the game corrupts the data that is found
	MSG_WriteData(&buf, &baselineSnap[bssMsgOff], bssMsgLen - bssMsgOff);
	MSG_WriteByte(&buf, 5);//This seems to fix demos ending after calling in laptop killstreaks for example harrier strikes
	MSG_WriteByte(&buf, 6);//FourDeltaone writes this
	buf.maxsize = (int)& cmpData;
	//*(int*)buf[4] = *(int*)buf[2];

	int compressedSize = CompressPacket(0, buf.data, buf.maxsize, buf.cursize);
	int fileCompressedSize = compressedSize + 4;

	FS_Write(&byte0, 1, *demoFile);
	FS_Write(serverMessageSequence, 4, *demoFile);
	//FS_Write(&buf[5], 4, *demoFile);
	FS_Write(&fileCompressedSize, 4, *demoFile);
	FS_Write(&byte8, 4, *demoFile);
	//FS_Write((void*)buf[2], buf[5], *demoFile);

	int pt1 = compressedSize;
	for (int i = 0; i < compressedSize; i += 1024)
	{
		int blk = pt1 - i;
		if (blk > 1024)
			blk = 1024;

		FS_Write((void*)(i + buf.maxsize), blk, *demoFile);
		pt1 = compressedSize;
	}

}
void __declspec(naked) BaselineToFileFunc() {
	*(INT*)0x6360B20 = 0;//Disable string table on start of demo, if it's the original table then it doesn't recognise the map in the demo
	*(INT*)0xAF5FA4 = 0;//Set Demo size back to 0. This is so the config string can reset
	WriteBaseline();

	__asm jmp baselineToFileRet
}


DWORD recordGamestateLoc = 0x4C3473;
//CallHook recordGamestate;

int tmpSeq;

void __declspec(naked) RecordGamestateFunc() {

	tmpSeq = *serverMessageSequence;
	tmpSeq--;

	FS_Write(&tmpSeq, 4, *demoFile);

	__asm retn
}

// --- demo playback timing ---
CallHook clAdjustTimeDeltaHook;
DWORD clAdjustTimeDeltaHookLoc = 0x4BCADE;

void __declspec(naked) CL_AdjustTimeDeltaHookStub()
{
	__asm
	{
		mov eax, 0AF5FECh // demoPlaying
		mov eax, [eax]
		test al, al
		jz returnStuff

		// delta doesn't drift for demos
		retn

		returnStuff :
		jmp clAdjustTimeDeltaHook.pOriginal
	}
}
StompHook serverTimedOutHook;
DWORD serverTimedOutHookLoc = 0x4C4B8C;
DWORD serverTimedOutHookRetn = 0x4C4BE6;
DWORD serverTimedOutHookContinue = 0x4C4B91;
void __declspec(naked) ServerTimedOutHookStub()
{
	__asm
	{
		mov eax, 0AF5FECh // demoPlaying
		mov eax, [eax]
		test al, al
		jz returnStuff
		jmp serverTimedOutHookRetn

		returnStuff :
		mov eax, 0B2BB90h
			jmp serverTimedOutHookContinue
	}
}
DWORD clParseGamestateHookLoc = 0x4BD0E1;
void __declspec(naked) clParseGamestateHookStub()
{
	__asm
	{
		mov ebx, [esp]
		mov[esp + 4], ebx
		//code we've overwritten
		add esp, 4
		mov ebx, eax

		test edi, edi //some kind of ID
		jne back
		pushad
		//call GetFS_Game
		popad

		back :
		ret
	}
}


CallHook execIsFSHook;
DWORD execIsFSHookLoc = 0x564C9A;

// note this function has to return 'int', as otherwise only the bottom byte will get cleared
int ExecIsFSHookFunc(const char* execFilename, const char* dummyMatch) { // dummyMatch isn't used by us
	// check if the file exists in our FS_* path
	if (FS_ReadFile(execFilename, NULL) >= 0)
	{
		return false;
	}

	return true;
}
void __declspec(naked) ExecIsFSHookStub() {
	__asm jmp ExecIsFSHookFunc
}

void PatchMW2_DemoRecording()
{
	gamestateWriteHook.initialize(gamestateWriteHookLoc, GamestateWriteHookStub);
	gamestateWriteHook.installHook();

	recordGamestate.initialize(recordGamestateLoc, RecordGamestateFunc);
	recordGamestate.installHook();


	baselineStoreHook.initialize(baselineStoreHookLoc, BaselineStoreHookFunc);
	baselineStoreHook.installHook();


	baselineToFile.initialize(baselineToFileLoc, BaselineToFileFunc);
	baselineToFile.installHook();

	clAdjustTimeDeltaHook.initialize(clAdjustTimeDeltaHookLoc, CL_AdjustTimeDeltaHookStub);
	clAdjustTimeDeltaHook.installHook();


	*(BYTE*)0x4CAF44 = 4;//Enables RECORDING: %s text
	*(BYTE*)0x4CAF4A = 4;//Enables RECORDING: %s text

	execIsFSHook.initialize(execIsFSHookLoc, ExecIsFSHookStub);
	execIsFSHook.installHook();
}
static BYTE originalCode[5];
static PBYTE originalEP = 0;

typedef LRESULT(WINAPI* DispatchMessage_t)(MSG*);
DispatchMessage_t oDispatchMessage;

int GetDemoSize()
{
	auto demosize = reinterpret_cast<int*>(0xAF5FA4);
	return *demosize;
}
int isDemoPlaying()
{
	auto IsDemoPlaying = reinterpret_cast<int*>(0xAF5FEC);
	return *IsDemoPlaying;
}
int GetConfigString()
{
	auto ConfigString = reinterpret_cast<int*>(0x6360B20);
	return *ConfigString;
}
int configstringvalue;
LRESULT CALLBACK mDispatchMessage(MSG* lpmsg)
{
	auto wParam = lpmsg->wParam;

	auto handled = false;

	if (isDemoPlaying() == 1)
	{
		*(INT*)0x6360B20 = 0; //Fix for fs_game issue when trying to play a demo
	}
	if (GetDemoSize() != 0)
	{
		*(INT*)0x6360B20 = configstringvalue; //Switch to original string table after demo is recording, this is to let players back in your lobby
	}

	switch (lpmsg->message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_F1:
		{
			if (GetConfigString() != 0)//We don't want to save the configstringvalue when it's 0
			{
				configstringvalue = GetConfigString();//Save original string table before we change it
				*(INT*)0x6360B20 = 0;//Disable string table on start of demo, if it's the original table then it doesn't recognise the map in the demo
				*(INT*)0xAF5FA4 = 0;//Set Demo size back to 0. This is so the config string can reset
				if (GetConfigString() == 0)//We only want to record when the config string is = to 0
				{
					Cbuf_AddText(0, "stoprecord; wait 10; record");//
				}
			}
		}
		break;

		}
	}
	return oDispatchMessage(lpmsg);
	return false;
}
void HookDispatchMessageA()
{
	DWORD DispatchMessageAddress = 0;

	while (!((DispatchMessageAddress = reinterpret_cast<unsigned long>(GetProcAddress(LoadLibraryA("User32.dll"), "DispatchMessageA")))))
		Sleep(250);

	oDispatchMessage = reinterpret_cast<DispatchMessage_t>(DetourFunction(reinterpret_cast<PBYTE>(DispatchMessageAddress), reinterpret_cast<PBYTE>(mDispatchMessage)));

}
void Main_UnprotectModule(HMODULE hModule)
{
	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

	// unprotect the entire PE image
	SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
	DWORD oldProtect;
	VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}
#pragma optimize("", off)
void Main_DoInit()
{
	// unprotect our entire PE image
	HMODULE hModule;
	if (SUCCEEDED(GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)Main_DoInit, &hModule)))
	{
		Main_UnprotectModule(hModule);
	}
	PatchMW2_DemoRecording();
	// return to the original EP
	memcpy(originalEP, &originalCode, sizeof(originalCode));
	__asm jmp originalEP
}

void Main_SetSafeInit()
{

	HMODULE hModule = GetModuleHandle(NULL);


	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

	Main_UnprotectModule(hModule);
	PatchMW2_DemoRecording();
	// back up original code
	PBYTE ep = (PBYTE)((DWORD)hModule + ntHeader->OptionalHeader.AddressOfEntryPoint);
	memcpy(originalCode, ep, sizeof(originalCode));

	// patch to call our EP
	int newEP = (int)Main_DoInit - ((int)ep + 5);
	ep[0] = 0xE9; // for some reason this doesn't work properly when run under the debugger
	memcpy(&ep[1], &newEP, 4);

	originalEP = ep;

}
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

		HookDispatchMessageA();
		Main_SetSafeInit();

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

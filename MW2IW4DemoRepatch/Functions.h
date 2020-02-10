#pragma once

#pragma managed

#pragma optimize("", on)
struct msg_t
{
	int overflowed;
	int readOnly;
	char* data;
	char* splitData;
	int maxsize;
	int cursize;
	int splitSize;
	int readcount;
	int bit;//Original size of FourDeltaOne code
	int lastEntityRef;
	int lengthoffset;//1.2.211 holds 2 extra values in msg_t.
};

typedef int(__cdecl* FS_ReadFile_t)(const char* path, char** buffer);
extern FS_ReadFile_t FS_ReadFile;
typedef void(__cdecl* MSG_Init_t)(void* msg, void* data, int maxsize);
extern MSG_Init_t MSG_Init;
typedef void(__cdecl* MSG_WriteByte_t)(msg_t* msg, unsigned char);
extern MSG_WriteByte_t MSG_WriteByte;
typedef int(__cdecl* FS_Write_t)(void* buffer, size_t size, int file);
extern FS_Write_t FS_Write;
typedef void(__cdecl* MSG_WriteData_t)(msg_t* msg, char*, size_t);
extern MSG_WriteData_t MSG_WriteData;
typedef void(__cdecl* MSG_WriteLong_t)(msg_t* msg, int);
extern MSG_WriteLong_t MSG_WriteLong;
typedef size_t(__cdecl* CompressPacket_t)(char const0, char* a2, int a3, int a4);
typedef void(__cdecl* Cbuf_AddText_t)(int localClientNum, const char* text);



Cbuf_AddText_t Cbuf_AddText = (Cbuf_AddText_t)0x563D10;
CompressPacket_t CompressPacket = (CompressPacket_t)0x56FD20;
MSG_WriteLong_t MSG_WriteLong = (MSG_WriteLong_t)0x56FEC0;
MSG_WriteByte_t MSG_WriteByte = (MSG_WriteByte_t)0x56FDE0;
MSG_WriteData_t MSG_WriteData = (MSG_WriteData_t)0x56FE30;
FS_ReadFile_t FS_ReadFile = (FS_ReadFile_t)0x5B3080;
FS_Write_t FS_Write = (FS_Write_t)0x5B0AF0;
MSG_Init_t MSG_Init = (MSG_Init_t)0x56FA70;

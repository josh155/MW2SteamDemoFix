#pragma once

typedef const char* (__cdecl* GetString_t)(const char* dvarName);
static GetString_t GetString = (GetString_t)0x5BD000;
auto ui_mapname = GetString("ui_mapname");

char* getPlayerName()
{
	return reinterpret_cast<char*>(0x665271C);
}
unsigned char value = *(reinterpret_cast<unsigned char*>(0x665271C));
//redone Skidrow, Terminal, Highrise ,Afghan, Wasteland, Derail, Estate, Favela, Invasion, Karachi, Quarry, Rundown, Rust
char baseline[1224]{ 0x01, 0x01, 0x00, 0x00, 0x6C, 0xD6, 0x21, 0x22, 0x4D, 0xBC, 0xD6, 0xFE, 0x4F, 0xC3, 0x4F, 0x45, 0x43, 0x54, 0x45, 0x44, 0x15, 0x5E, 0x37, 0x22, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x73, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x72, 0x61, 0x77, 0x53, 0x70, 0x65, 0x63, 0x74, 0x61, 0x74, 0x6F, 0x72, 0x4D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x73, 0x20, 0x22, 0x31, 0x22, 0x20, 0x67, 0x5F, 0x63, 0x6F, 0x6D, 0x70, 0x61, 0x73, 0x73, 0x53, 0x68, 0x6F, 0x77, 0x45, 0x6E, 0x65, 0x6D, 0x69, 0x65, 0x73, 0x20, 0x22, 0x30, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x73, 0x63, 0x6F, 0x72, 0x65, 0x62, 0x6F, 0x61, 0x72, 0x64, 0x50, 0x69, 0x6E, 0x67, 0x47, 0x72, 0x61, 0x70, 0x68, 0x20, 0x22, 0x31, 0x22, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x73, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x49, 0x63, 0x6F, 0x6E, 0x48, 0x65, 0x69, 0x67, 0x68, 0x74, 0x20, 0x22, 0x32, 0x35, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x49, 0x63, 0x6F, 0x6E, 0x57, 0x69, 0x64, 0x74, 0x68, 0x20, 0x22, 0x32, 0x35, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x49, 0x63, 0x6F, 0x6E, 0x4F, 0x66, 0x66, 0x73, 0x65, 0x74, 0x20, 0x22, 0x35, 0x30, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x50, 0x6F, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x48, 0x65, 0x69, 0x67, 0x68, 0x74, 0x20, 0x22, 0x31, 0x32, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x50, 0x6F, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x57, 0x69, 0x64, 0x74, 0x68, 0x20, 0x22, 0x32, 0x35, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x50, 0x6F, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x50, 0x69, 0x76, 0x6F, 0x74, 0x20, 0x22, 0x31, 0x32, 0x20, 0x32, 0x37, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x66, 0x6F, 0x76, 0x73, 0x63, 0x61, 0x6C, 0x65, 0x20, 0x22, 0x31, 0x22, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x73, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x65, 0x61, 0x64, 0x43, 0x68, 0x61, 0x74, 0x57, 0x69, 0x74, 0x68, 0x44, 0x65, 0x61, 0x64, 0x20, 0x22, 0x30, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x65, 0x61, 0x64, 0x43, 0x68, 0x61, 0x74, 0x57, 0x69, 0x74, 0x68, 0x54, 0x65, 0x61, 0x6D, 0x20, 0x22, 0x31, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x65, 0x61, 0x64, 0x48, 0x65, 0x61, 0x72, 0x54, 0x65, 0x61, 0x6D, 0x4C, 0x69, 0x76, 0x69, 0x6E, 0x67, 0x20, 0x22, 0x31, 0x22, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x65, 0x61, 0x64, 0x48, 0x65, 0x61, 0x72, 0x41, 0x6C, 0x6C, 0x4C, 0x69, 0x76, 0x69, 0x6E, 0x67, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x05, 0x00, 0x00, 0x00, 0x73, 0x20, 0x63, 0x67, 0x5F, 0x65, 0x76, 0x65, 0x72, 0x79, 0x6F, 0x6E, 0x65, 0x68, 0x65, 0x61, 0x72, 0x73, 0x65, 0x76, 0x65, 0x72, 0x79, 0x6F, 0x6E, 0x65, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x06, 0x00, 0x00, 0x00, 0x73, 0x20, 0x75, 0x69, 0x5F, 0x61, 0x6C, 0x74, 0x73, 0x63, 0x65, 0x6E, 0x65, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x07, 0x00, 0x00, 0x00, 0x73, 0x20, 0x75, 0x69, 0x5F, 0x61, 0x64, 0x72, 0x65, 0x6E, 0x61, 0x6C, 0x69, 0x6E, 0x65, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x4F, 0x20, 0x22, 0x74, 0x68, 0x65, 0x72, 0x6D, 0x61, 0x6C, 0x5F, 0x6D, 0x70, 0x22, 0x20, 0x31, 0x30, 0x30, 0x30, 0x00, 0x01, 0x09, 0x00, 0x00, 0x00, 0x52, 0x20, 0x31, 0x31, 0x37, 0x38, 0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x73, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x31, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x32, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x33, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x34, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x35, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x36, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x20, 0x75, 0x69, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x5F, 0x37, 0x5F, 0x72, 0x65, 0x66, 0x20, 0x22, 0x22, 0x00, 0x01, 0x0B, 0x00, 0x00, 0x00, 0x73, 0x20, 0x75, 0x69, 0x5F, 0x70, 0x72, 0x6F, 0x6D, 0x6F, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x0C, 0x00, 0x00, 0x00, 0x73, 0x20, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x5F, 0x73, 0x75, 0x6D, 0x6D, 0x61, 0x72, 0x79, 0x5F, 0x78, 0x70, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x0D, 0x00, 0x00, 0x00, 0x73, 0x20, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x5F, 0x73, 0x75, 0x6D, 0x6D, 0x61, 0x72, 0x79, 0x5F, 0x73, 0x63, 0x6F, 0x72, 0x65, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x0E, 0x00, 0x00, 0x00, 0x73, 0x20, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x5F, 0x73, 0x75, 0x6D, 0x6D, 0x61, 0x72, 0x79, 0x5F, 0x63, 0x68, 0x61, 0x6C, 0x6C, 0x65, 0x6E, 0x67, 0x65, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x73, 0x20, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x5F, 0x73, 0x75, 0x6D, 0x6D, 0x61, 0x72, 0x79, 0x5F, 0x6D, 0x61, 0x74, 0x63, 0x68, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x73, 0x20, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x5F, 0x73, 0x75, 0x6D, 0x6D, 0x61, 0x72, 0x79, 0x5F, 0x6D, 0x69, 0x73, 0x63, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x11, 0x00, 0x00, 0x00, 0x73, 0x20, 0x75, 0x69, 0x5F, 0x6F, 0x70, 0x65, 0x6E, 0x73, 0x75, 0x6D, 0x6D, 0x61, 0x72, 0x79, 0x20, 0x22, 0x30, 0x22, 0x00, 0x01, 0x12, 0x00, 0x00, 0x00, 0x44, 0x20, 0x30, 0x00, 0x01, 0x13, 0x00, 0x00, 0x00, 0x43, 0x20, 0x30, 0x00, 0x01, 0x14, 0x00, 0x00, 0x00, 0x72, 0x00, 0x01, 0x15, 0x00, 0x00, 0x00, 0x48, 0x00, 0x01, 0x16, 0x00, 0x00, 0x00, 0x73, 0x20, 0x63, 0x67, 0x5F, 0x6F, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x69, 0x76, 0x65, 0x54, 0x65, 0x78, 0x74, 0x20, 0x22, 0x22, 0x00, 0x01, 0x17, 0x00, 0x00, 0x00, 0x73, 0x20, 0x67, 0x5F, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x4D, 0x61, 0x69, 0x6E, 0x4D, 0x65, 0x6E, 0x75, 0x20, 0x22, 0x74, 0x65, 0x61, 0x6D, 0x5F, 0x6D, 0x61, 0x72, 0x69, 0x6E, 0x65, 0x73, 0x6F, 0x70, 0x66, 0x6F, 0x72, 0x22, 0x00, 0x01, 0x18, 0x00, 0x00, 0x00, 0x6A, 0x00, 0x01, 0x19, 0x00, 0x00, 0x00, 0x71, 0x20, 0x32, 0x00, 0x01, 0x1A, 0x00, 0x00, 0x00, 0x64, 0x20, 0x31, 0x36, 0x38, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x72, 0x61, 0x77, 0x43, 0x72, 0x6F, 0x73, 0x73, 0x68, 0x61, 0x69, 0x72, 0x00, 0x01, 0x1B, 0x00, 0x00, 0x00, 0x64, 0x20, 0x33, 0x36, 0x38, 0x20, 0x31, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x00, 0x64, 0x20, 0x31, 0x36, 0x39, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x72, 0x61, 0x77, 0x43, 0x72, 0x6F, 0x73, 0x73, 0x68, 0x61, 0x69, 0x72, 0x4E, 0x61, 0x6D, 0x65, 0x73, 0x00, 0x01, 0x1D, 0x00, 0x00, 0x00, 0x64, 0x20, 0x33, 0x36, 0x39, 0x20, 0x31, 0x00, 0x01, 0x1E, 0x00, 0x00, 0x00, 0x64, 0x20, 0x31, 0x37, 0x30, 0x20, 0x63, 0x67, 0x5F, 0x64, 0x72, 0x61, 0x77, 0x54, 0x61, 0x6C, 0x6B, 0x00, 0x01, 0x1F, 0x00, 0x00, 0x00, 0x64, 0x20, 0x33, 0x37, 0x30, 0x20, 0x41, 0x4C, 0x4C, 0x00, 0x01, 0x20, 0x00, 0x00, 0x00, 0x64, 0x20, 0x31, 0x37, 0x31, 0x20, 0x63, 0x67, 0x5F, 0x68, 0x75, 0x64, 0x47, 0x72, 0x65, 0x6E, 0x61, 0x64, 0x65, 0x49, 0x63, 0x6F, 0x6E, 0x4D, 0x61, 0x78, 0x52, 0x61, 0x6E, 0x67, 0x65, 0x46, 0x72, 0x61, 0x67, 0x00, 0x01, 0x21, 0x00, 0x00, 0x00, 0x64, 0x20, 0x33, 0x37, 0x31, 0x20, 0x32, 0x35, 0x30, 0x00, 0x00, 0x84, 0x03, 0x00, 0x00, 0x00, 0x0C };









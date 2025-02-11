#include "utils.h"
#include <windows.h>
#include <string>

std::string utils::executablePath()
{
    WCHAR path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    std::wstring ws(path);
    return std::string(ws.begin(), ws.end());
}
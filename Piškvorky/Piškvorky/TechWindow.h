#include <windows.h>
#include <string>

std::wstring stringToWstring(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}
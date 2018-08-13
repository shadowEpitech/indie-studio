//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Windows class definition
//

#ifndef _WINDOWS_HPP_
#define _WINDOWS_HPP_

#include <windows.h>
#include <string>

class Windows
{
    public:
        static std::string  BrowseFolder();
        static TCHAR        *SearchFolder(TCHAR *path);
        static bool          copyFolder(const wchar_t *pathInstall);
        static bool          createSymlink();
};

#endif /* _WINDOWS_HPP_ */
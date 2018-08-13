//
// Created by arthu on 18/06/2018.
//

#include <cstring>
#include <cstdio>
#include <shlobj.h>
#include <fstream>
#include <iostream>
#include "Windows.hpp"

std::string Windows::BrowseFolder()
{
    TCHAR       path[MAX_PATH];
    BROWSEINFO  bi = {nullptr};
    bi.lpszTitle = ("All Folders Automatically Recursed.");
    LPITEMIDLIST    pidl = SHBrowseForFolder ( &bi );
    if (pidl != nullptr) {
        SHGetPathFromIDList (pidl, path);
        SetCurrentDirectory(path);
        SearchFolder(path);
        IMalloc *imalloc = nullptr;
        if (SUCCEEDED(SHGetMalloc(&imalloc))) {
            imalloc->Free(pidl);
            imalloc->Release();
        }
    }
    std::string installPath = path;
    std::size_t found = installPath.find_last_of("/\\");
    return installPath.substr(0, found);
}

TCHAR   *Windows::SearchFolder(TCHAR *path )
{
    WIN32_FIND_DATA FindFileData;
    HANDLE          hFind;
    TCHAR           pathbak[MAX_PATH];
    strcpy(pathbak, path);
    hFind = FindFirstFile ("*.*", &FindFileData);
    do {
        if ( hFind != INVALID_HANDLE_VALUE ) {
            if ( ! ( strcmp( FindFileData.cFileName, "." ) ) ||
                 ! ( strcmp( FindFileData.cFileName, ".." ) ) )
                continue;
            strcpy(path, pathbak);
            sprintf(path, "%s\\%s", path, FindFileData.cFileName);
            if ((SetCurrentDirectory(path )))
                SearchFolder(path);
        }
    }
    while (FindNextFile(hFind, &FindFileData)
            && hFind != INVALID_HANDLE_VALUE);
    FindClose(hFind);
    return path;
}

bool          Windows::copyFolder(const wchar_t *pathInstall)
{
    std::size_t     len = wcslen(pathInstall) + 1;
    char            to[len];

    std::cerr << "yolo" << std::endl;
    wcstombs(to, pathInstall, sizeof(to));
    SHFILEOPSTRUCT s = {nullptr};
    s.wFunc = FO_COPY;
    s.fFlags = FOF_SILENT;
    s.pTo = to;
    s.pFrom = R"(C:\Users\arthu\Documents\cpp_indie_studio\Bomberman)";
    SHFileOperation(&s);
    return true;
}

bool          Windows::createSymlink()
{
    // int val(CreateSymbolicLink(""));
    std::cout << "hello : " << Windows::SearchFolder(const_cast<TCHAR *>
						  ("Desktop"))
              << std::endl;
}

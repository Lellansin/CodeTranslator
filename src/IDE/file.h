
#ifndef _FILE_H_
#define _FILE_H_

BOOL LoadTextFileToEdit(HWND hEdit, LPCTSTR pszFileName);
BOOL SaveTextFileFromEdit(HWND hEdit, LPCTSTR pszFileName);
void DoFileOpen(HWND hwnd);
void DoFileSave(HWND hwnd);

#endif
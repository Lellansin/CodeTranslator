
#include <windows.h>
#include <commctrl.h>

#include "resource.h"
#include "main.h"
#include "file.h"

const char g_szClassName[] = "myWindowClass";
const char g_szChildClassName[] = "myMDIChildWindowClass";

HWND g_hMDIClient = NULL;
HWND g_hMainWindow = NULL;

/***
 * 创建 MDI 子窗口
 */
HWND CreateNewMDIChild(HWND hMDIClient)
{
	MDICREATESTRUCT mcs;
	HWND hChild;

	mcs.szTitle = "[Untitled]";
	mcs.szClass = g_szChildClassName;
	mcs.hOwner  = GetModuleHandle(NULL);
	mcs.x = mcs.cx = CW_USEDEFAULT;
	mcs.y = mcs.cy = CW_USEDEFAULT;
	mcs.style = MDIS_ALLCHILDSTYLES;

	hChild = (HWND)SendMessage(hMDIClient, WM_MDICREATE, 0, (LONG)&mcs);
	if(!hChild)
	{
		MessageBox(hMDIClient, "MDI 子窗口 创建失败.", "错误", MB_ICONEXCLAMATION | MB_OK);
	}
	return hChild;
}

/***
 * 主窗口过程
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
		{
			HWND hTool;	// Toolbar 句柄
			TBBUTTON tbb[3];
			TBADDBITMAP tbab;

			HWND hStatus;	// StatusBar 句柄
			int statwidths[] = {100, -1};

			CLIENTCREATESTRUCT ccs;

			// 创建一个 MDI Client

			// Find window menu where children will be listed
			ccs.hWindowMenu  = GetSubMenu(GetMenu(hwnd), 2);
			ccs.idFirstChild = ID_MDI_FIRSTCHILD;

			g_hMDIClient = CreateWindowEx(WS_EX_CLIENTEDGE, "mdiclient", NULL,
				WS_CHILD | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL | WS_VISIBLE,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				hwnd, (HMENU)IDC_MAIN_MDI, GetModuleHandle(NULL), (LPVOID)&ccs);

			if(g_hMDIClient == NULL)
				MessageBox(hwnd, "无法创建 MDI client.", "Error", MB_OK | MB_ICONERROR);

			// 创建 Toolbar 工具条

			hTool = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD | WS_VISIBLE, 0, 0, 0, 0,
				hwnd, (HMENU)IDC_MAIN_TOOL, GetModuleHandle(NULL), NULL);
			if(hTool == NULL)
				MessageBox(hwnd, "无法创建 tool bar.", "Error", MB_OK | MB_ICONERROR);

			// 出于兼容性发送 TB_BUTTON STRUCT SIZE 消息, 传入当前的 TB button 的大小
			SendMessage(hTool, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
			
			// 向工具条发送添加图片的方法
			tbab.hInst = HINST_COMMCTRL;
			tbab.nID = IDB_STD_SMALL_COLOR;
			SendMessage(hTool, TB_ADDBITMAP, 0, (LPARAM)&tbab);

			// 设置工具条按钮
			ZeroMemory(tbb, sizeof(tbb));
			tbb[0].iBitmap = STD_FILENEW;
			tbb[0].fsState = TBSTATE_ENABLED;
			tbb[0].fsStyle = TBSTYLE_BUTTON;
			tbb[0].idCommand = ID_FILE_NEW;

			tbb[1].iBitmap = STD_FILEOPEN;
			tbb[1].fsState = TBSTATE_ENABLED;
			tbb[1].fsStyle = TBSTYLE_BUTTON;
			tbb[1].idCommand = ID_FILE_OPEN;

			tbb[2].iBitmap = STD_FILESAVE;
			tbb[2].fsState = TBSTATE_ENABLED;
			tbb[2].fsStyle = TBSTYLE_BUTTON;
			tbb[2].idCommand = ID_FILE_SAVEAS;

			// 添加工具条按钮
			SendMessage(hTool, TB_ADDBUTTONS, sizeof(tbb)/sizeof(TBBUTTON), (LPARAM)&tbb);

			// 创建 Status bar
			hStatus = CreateWindowEx(0, STATUSCLASSNAME, NULL,
				WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0,
				hwnd, (HMENU)IDC_MAIN_STATUS, GetModuleHandle(NULL), NULL);

			SendMessage(hStatus, SB_SETPARTS, sizeof(statwidths)/sizeof(int), (LPARAM)statwidths);
			SendMessage(hStatus, SB_SETTEXT, 0, (LPARAM)"Hi there :)");
		}
		break;
		case WM_SIZE:
		{
			HWND hTool;
			RECT rcTool;
			int iToolHeight;

			HWND hStatus;
			RECT rcStatus;
			int iStatusHeight;

			HWND hMDI;
			int iMDIHeight;
			RECT rcClient;

			// Size toolbar and get height

			hTool = GetDlgItem(hwnd, IDC_MAIN_TOOL);
			SendMessage(hTool, TB_AUTOSIZE, 0, 0);

			GetWindowRect(hTool, &rcTool);
			iToolHeight = rcTool.bottom - rcTool.top;

			// Size status bar and get height

			hStatus = GetDlgItem(hwnd, IDC_MAIN_STATUS);
			SendMessage(hStatus, WM_SIZE, 0, 0);

			GetWindowRect(hStatus, &rcStatus);
			iStatusHeight = rcStatus.bottom - rcStatus.top;

			// Calculate remaining height and size edit

			GetClientRect(hwnd, &rcClient);

			iMDIHeight = rcClient.bottom - iToolHeight - iStatusHeight;

			hMDI = GetDlgItem(hwnd, IDC_MAIN_MDI);
			SetWindowPos(hMDI, NULL, 0, iToolHeight, rcClient.right, iMDIHeight, SWP_NOZORDER);
		}
		break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case ID_FILE_EXIT:
					PostMessage(hwnd, WM_CLOSE, 0, 0);
				break;
				case ID_FILE_NEW:
					CreateNewMDIChild(g_hMDIClient);
				break;
				case ID_FILE_OPEN:
				{
					HWND hChild = CreateNewMDIChild(g_hMDIClient);
					if(hChild)
					{
						DoFileOpen(hChild);	
					}
				}
				break;
				case ID_FILE_CLOSE:
				{
					HWND hChild = (HWND)SendMessage(g_hMDIClient, WM_MDIGETACTIVE,0,0);
					if(hChild)
					{
						SendMessage(hChild, WM_CLOSE, 0, 0);
					}
				}
				break;
				case ID_WINDOW_TILE:
					SendMessage(g_hMDIClient, WM_MDITILE, 0, 0);
				break;
				case ID_WINDOW_CASCADE:
					SendMessage(g_hMDIClient, WM_MDICASCADE, 0, 0);
				break;
				default:
				{
					if(LOWORD(wParam) >= ID_MDI_FIRSTCHILD)
					{
						DefFrameProc(hwnd, g_hMDIClient, WM_COMMAND, wParam, lParam);
					}
					else 
					{
						HWND hChild = (HWND)SendMessage(g_hMDIClient, WM_MDIGETACTIVE,0,0);
						if(hChild)
						{
							SendMessage(hChild, WM_COMMAND, wParam, lParam);
						}
					}
				}
			}
		break;
		default:
			return DefFrameProc(hwnd, g_hMDIClient, msg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK MDIChildWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
		{
			HFONT hfDefault;
			HWND hEdit;

			// Create Edit Control

			hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", 
				WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 
				0, 0, 100, 100, hwnd, (HMENU)IDC_CHILD_EDIT, GetModuleHandle(NULL), NULL);
			if(hEdit == NULL)
				MessageBox(hwnd, "无法创建 edit box.", "Error", MB_OK | MB_ICONERROR);

			hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
			SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE, 0));
		}
		break;
		case WM_MDIACTIVATE:
		{
			HMENU hMenu, hFileMenu;
			UINT EnableFlag;

			hMenu = GetMenu(g_hMainWindow);
			if(hwnd == (HWND)lParam)
			{	   //being activated, enable the menus
				EnableFlag = MF_ENABLED;
			}
			else
			{						   //being de-activated, gray the menus
				EnableFlag = MF_GRAYED;
			}

			EnableMenuItem(hMenu, 1, MF_BYPOSITION | EnableFlag);
			EnableMenuItem(hMenu, 2, MF_BYPOSITION | EnableFlag);

			hFileMenu = GetSubMenu(hMenu, 0);
			EnableMenuItem(hFileMenu, ID_FILE_SAVEAS, MF_BYCOMMAND | EnableFlag);

			EnableMenuItem(hFileMenu, ID_FILE_CLOSE, MF_BYCOMMAND | EnableFlag);
			EnableMenuItem(hFileMenu, ID_FILE_CLOSEALL, MF_BYCOMMAND | EnableFlag);

			DrawMenuBar(g_hMainWindow);
		}
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case ID_FILE_OPEN:
					DoFileOpen(hwnd);
				break;
				case ID_FILE_SAVEAS:
					DoFileSave(hwnd);
				break;
				case ID_EDIT_CUT:
					SendDlgItemMessage(hwnd, IDC_CHILD_EDIT, WM_CUT, 0, 0);
				break;
				case ID_EDIT_COPY:
					SendDlgItemMessage(hwnd, IDC_CHILD_EDIT, WM_COPY, 0, 0);
				break;
				case ID_EDIT_PASTE:
					SendDlgItemMessage(hwnd, IDC_CHILD_EDIT, WM_PASTE, 0, 0);
				break;
			}
		break;
		case WM_SIZE:
		{
			HWND hEdit;
			RECT rcClient;

			// Calculate remaining height and size edit

			GetClientRect(hwnd, &rcClient);

			hEdit = GetDlgItem(hwnd, IDC_CHILD_EDIT);
			SetWindowPos(hEdit, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
		}
		return DefMDIChildProc(hwnd, msg, wParam, lParam);
		default:
			return DefMDIChildProc(hwnd, msg, wParam, lParam);
	
	}
	return 0;
}

BOOL SetUpMDIChildWindowClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	// 初始化 MDI 窗口
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc	 = MDIChildWndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_3DFACE+1);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = g_szChildClassName;
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	// 注册 MDI 窗口
	if(!RegisterClassEx(&wc))
	{
		MessageBox(0, "无法注册子窗口", "错误", MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}
	else
		return TRUE;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	// InitCommonControls();

	// 初始化窗口结构体
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = 0;
	wc.lpfnWndProc	 = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	// 注册主窗口
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "窗口注册失败!", "错误", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// 注册MDI窗口
	if(!SetUpMDIChildWindowClass(hInstance))
		return 0;

	// 创建窗口
	hwnd = CreateWindowEx(
		0,
		g_szClassName,
		"CodeTranslator",
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		// GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
		NULL, NULL, hInstance, NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL, "窗口创建失败!", "错误", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	g_hMainWindow = hwnd;

	// 显示窗口
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// 消息循环
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		if (!TranslateMDISysAccel(g_hMDIClient, &Msg))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
	return Msg.wParam;
}

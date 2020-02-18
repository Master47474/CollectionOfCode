// To Run gcc -Wall -mwindows "file" -o main.exe
#include <windows.h>
#include "Resource.h"


const char g_szClassName[] = "myWindowClass";
HWND g_hToolbar = NULL;

BOOL CALLBACK ToolDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);


//step 4: the window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){

  switch(msg){
    case WM_CREATE:
    // do this with in rescources next
      {
        HFONT hfDefault;
        HWND hEdit;

        hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
            0, 0, 100, 100, hwnd, (HMENU)IDC_MAIN_EDIT, GetModuleHandle(NULL), NULL);
        if(hEdit == NULL)
            MessageBox(hwnd, "Could not create edit box.", "Error", MB_OK | MB_ICONERROR);

        hfDefault = GetStockObject(DEFAULT_GUI_FONT);
        SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE, 0));
      }
    break;
    case WM_SIZE:
    {
        HWND hEdit;
        RECT rcClient;

        GetClientRect(hwnd, &rcClient);

        hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
        SetWindowPos(hEdit, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
    }
    break;
    case WM_COMMAND:
      switch (LOWORD(wParam)) {
        case ID_FILE_EXIT:
          PostMessage(hwnd, WM_CLOSE, 0, 0);
        break;
        case ID_STUFF_GO:
          {// <-- making a variable in a switch statement we need the braces
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, szFileName, "This Program is:", MB_OK | MB_ICONINFORMATION);
          }
        break;
        case ID_WINDOW_SHOW:
          ShowWindow(g_hToolbar, SW_SHOW);
        break;
        case ID_WINDOW_HIDE:
          ShowWindow(g_hToolbar, SW_HIDE);
        break;
      }
    break;
    case WM_CLOSE:
      DestroyWindow(hwnd);
    break;
    case WM_DESTROY:
      DestroyWindow(g_hToolbar);
      PostQuitMessage(0);
    break;
    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}



// main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

  WNDCLASSEX wc;
  HWND hwnd;
  MSG Msg;

  //step 1: registering the window class
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = 0;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));//LoadIcon(NULL, IDI_APPLICATION);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
  wc.lpszMenuName = NULL;
  wc.lpszClassName = g_szClassName;
  wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));//LoadIcon(NULL, IDI_APPLICATION);

  if(!RegisterClassEx(&wc)){
    MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }


  // step 2: creating the window
  hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, "TITLE OF the window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 320, 240, NULL, NULL, hInstance, NULL);

  if (hwnd == NULL){
    MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  // step 3: the message loop
  while(GetMessage(&Msg, NULL, 0, 0) > 0){
    if(!IsDialogMessage(g_hToolbar, &Msg)){
      TranslateMessage(&Msg);
      DispatchMessage(&Msg);
    }
  }

  return Msg.wParam;

}





BOOL LoadTextFileToEdit(HWND hEdit, LPCTSTR pszFileName){
  HANDLE hFile;
  BOOL BSuccess = FALSE;

  hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

  if (hFile != INVALID_HANDLE_VALUE){
    DWORD dwFileSize;

    dwFileSize = GetFileSize(hFile, NULL);
    if(dwFileSize != 0xFFFFFFFF){
      LPSTR pszFileText;
      pszFileText = GlobalAlloc(GPTR, dwFileSize + 1);

      if(pszFileText != NULL){
        DWORD dwRead;

        if(ReadFile(hFile, pszFileText, dwFileSize, &dwRead, NULL)){
          pszFileText[dwFileSize] = 0; // add null terminator
          if(setWindowText(hEdit, pszFileText))
            BSuccess = TRUE;
        }
        GlobalFree(pszFileText);
      }
    }
    CloseHandle(hFile);
  }
  return BSuccess;
}

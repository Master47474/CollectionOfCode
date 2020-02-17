
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
        g_hToolbar = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_TOOLBAR), hwnd, ToolDlgProc);
        if(g_hToolbar != NULL){
          ShowWindow(g_hToolbar, SW_SHOW);
        }else{
          MessageBox(hwnd, "CreateDialog returned NULL", "Warning!", MB_OK | MB_ICONINFORMATION);
        }

        HMENU hMenu, hSubMenu;
        HICON hIcon, hIconSm;

        hMenu = CreateMenu();

        hSubMenu = CreatePopupMenu();
        //                              ------------ the command which also gets put through the WM COMMAND switch down below
        AppendMenu(hSubMenu, MF_STRING, ID_FILE_EXIT, "E&xit");
        AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&File");

        hSubMenu = CreatePopupMenu();
        AppendMenu(hSubMenu, MF_STRING, ID_STUFF_GO, "&Go");
        AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Stuff");

        hSubMenu = CreatePopupMenu();
        AppendMenu(hSubMenu, MF_STRING, ID_WINDOW_SHOW, "&Show");
        AppendMenu(hSubMenu, MF_STRING, ID_WINDOW_HIDE, "&Hide");
        AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Ect");

        SetMenu(hwnd, hMenu);

        hIcon = LoadImage(NULL, "my_icon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
        if(hIcon)
          SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
        else
          MessageBox(hwnd, "Could not load large icon!", "Error", MB_OK | MB_ICONERROR);

        hIconSm = LoadImage(NULL, "my_icon.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
        if(hIconSm)
          SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIconSm);
        else
          MessageBox(hwnd, "Could not load small icon!", "Error", MB_OK | MB_ICONERROR);


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

BOOL CALLBACK ToolDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
  switch(Message){
    case WM_COMMAND:
      switch(LOWORD(wParam)){
        case IDC_PRESS:
          MessageBox(hwnd, "Hi!", "This is a message", MB_OK | MB_ICONEXCLAMATION);
        break;
        case IDC_OTHER:
          MessageBox(hwnd, "Bye!", "THIS IS ALSO A message", MB_OK | MB_ICONEXCLAMATION);
        break;
      }
    break;
    default:
      return FALSE;
  }
  return TRUE;
}

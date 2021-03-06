#include <windows.h>
#include "resource.h"


const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);



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
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return Msg.wParam;

}



//step 4: the window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){

  switch(msg){
    //creating drop downs
    case WM_CREATE:
      {
        HMENU hMenu, hSubMenu;
        HICON hIcon, hIconSm;

        hMenu = CreateMenu();

        hSubMenu = CreatePopupMenu();
        //                              ------------ the command which also gets put through the WM COMMAND switch down below
        AppendMenu(hSubMenu, MF_STRING, ID_FILE_EXIT, "E&xit");
        AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&File");

        hSubMenu = CreatePopupMenu();
        AppendMenu(hSubMenu, MF_STRING, ID_HELP_ABOUT, "&Go"); // replace wthj ID_STUFF_GO
        AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Stuff");

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
        case ID_HELP_ABOUT:
          {
            int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
            if(ret == IDOK){
              MessageBox(hwnd, "Dialog Exitid with IDOK", "NOTICE", MB_OK | MB_ICONINFORMATION);
            }else if(ret == IDCANCEL){
              MessageBox(hwnd, "dialog Exitied with IDCANCEL", "Notice", MB_OK | MB_ICONINFORMATION);
            }else if(ret == -1){
              MessageBox(hwnd, "DIALOG failed", "Error", MB_OK | MB_ICONINFORMATION);
            }
          }
        break;
      }
    case WM_CLOSE:
      DestroyWindow(hwnd);
    break;
    case WM_DESTROY:
      PostQuitMessage(0);
    break;
    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}


BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam){
  switch (Message) {
    case WM_INITDIALOG:

    break;
    case WM_COMMAND:
      switch(LOWORD(wParam)){
        case IDOK:
          EndDialog(hwnd, IDOK);
        break;
        case IDCANCEL:
          EndDialog(hwnd, IDCANCEL);
      }
    break;
    default:
      return FALSE;
  }
  return TRUE;
}

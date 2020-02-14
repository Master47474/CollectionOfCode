#include <windows.h>
#include "resource.h"

const char g_szClassName[] = "myWindowClass";

//step 4: the window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){

  switch(msg){
    // tells you the path of the program running
    case WM_LBUTTONDOWN:
      {// <-- making a variable in a switch statement we need the braces
        char szFileName[MAX_PATH];
        HINSTANCE hInstance = GetModuleHandle(NULL);

        GetModuleFileName(hInstance, szFileName, MAX_PATH);
        MessageBox(hwnd, szFileName, "This Program is:", MB_OK | MB_ICONINFORMATION);
      }
    break;
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

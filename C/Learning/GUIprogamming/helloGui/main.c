#include <windows.h>


// same as main for win32 programs
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    MessageBox(NULL, "Hello GUI!", "Note", MB_OK);
    return 0;

}

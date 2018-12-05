#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
using namespace std;
#include "applicant.h"
void gotoxy(int x, int y){
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(output, coord);

}
int main()
{
    char flag = 'f';
    applicant a;
    char ch;
    while(1){
        system("cls");
        gotoxy(31, 8);
        cout<< " Credit Calculation";
        gotoxy(31,9);
        cout<< "--------------------";
        gotoxy(22, 12);
        cout << "1 - Enter loan Applicant Details";
        gotoxy(22, 13);
        cout << "2 - Display Credit Score";
        gotoxy(22, 14);
        cout << "3 - Exit";
        gotoxy(22, 16);
        cout << "Select an option by typing the Numeric code : ";
        cin >> ch;
        //ch = getch();
        switch(ch){
            case('1'):{
                a.getdata();
                a.display_score();
                flag = 't';
                break;
            }
            case('2'):{
                if(flag == 'f'){
                    gotoxy(22, 18);
                    cout << "Loan Applicant's Details not yet entered! Press any Key to Continue...";
                    getch();
                    break;
                }
                else{
                    a.display_score();
                    break;
                }

            }
            case('3'):{
                exit(1);
                break;
            }

            default:
                gotoxy(22,18);
                cout << "Invalid Choice press any Key to Continue.... ";
                getch();
        }
    }
    cin.get();
    return 0;
}

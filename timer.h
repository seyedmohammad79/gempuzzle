#ifndef TIMER_H
#define TIMER_H
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

using namespace std;

int hours = 0;
int minutes = 0;
int seconds = 0;

void displayClock()

{
    system("cls");

    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);

    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    //cout << setfill(' ') << setw(55) << " --------------------------\n";
}
void timer(int n , int &d)
{
    while (seconds<=n) {

        displayClock();
        sleep(1);
        seconds++;
        if (seconds == 60) {
            minutes++;
            if (minutes == 60) {
                hours++;
                minutes = 0;
            }
            seconds = 0;
        }
    }
    cout<<"****** Game Over ******"<<endl;
    d=0;
//    return;
}


#endif // TIMER_H

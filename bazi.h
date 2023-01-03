#ifndef BAZI_H
#define BAZI_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "timer.h"

using namespace std;


const int arraySize = 4;
string homes[ arraySize ] [ arraySize ] = {{"1","2","3","4"},
                                           {"5","6","7","8"},
                                           {"9","10","11","12"},
                                           {"13","14"," ","15"}};

string check  [ arraySize ] [ arraySize ] = {{"1","2","3","4"},
                                             {"5","6","7","8"},
                                             {"9","10","11","12"},
                                             {"13","14"," ","15"}};

int vs = 3; // vertical space Position
int hs = 2; // h space Position

void moveUp()
{
    int vp = vs;
    if(vp + 1 < 4 && vp >= 0){

        homes[vs][hs] = homes[vs + 1][hs];
        homes[vs + 1][hs] = ' ';
        vs += 1;
    }
}
void moveDown()
{
    int vp = vs;
    if(vp + 1 <= 4 && vp > 0){

        homes[vs][hs] = homes[vs - 1][hs];
        homes[vs - 1][hs] = ' ';
        vs -= 1;
    }
}
void moveRight()
{
    int hp = hs;
    if(hp + 1 <= 4 && hp > 0){

        homes[vs][hs] = homes[vs][hs - 1];
        homes[vs][hs - 1] = ' ';
        hs -= 1;
    }
}
void moveLeft()
{
    int hp = hs;
    if(hp + 1 < 4 && hp >= 0){

        homes[vs][hs] = homes[vs][hs + 1];
        homes[vs][hs + 1] = ' ';
        hs += 1;
    }
}
void undo(char s[],int f){
    if(s[f-1]=='w' || s[f-1]=='W'){
        moveDown();
        return;
    }
    if(s[f-1]=='z' || s[f-1]=='Z'){
        moveUp();
        return;
    }
    if(s[f-1]=='a' || s[f-1]=='A'){
        moveRight();
        return;
    }
    if(s[f-1]=='s' || s[f-1]=='S'){
        moveLeft();
        return;
    }
    if(s[f-1]=='u' || s[f-1]=='U'){
        undo(s,f-1);
    }
}
void randomise() // randomize the array
{
    for(int i = 0; i < 20000; i++)
    {
        int a = 1 + rand() % 4;
        switch(a)
        {
        case 1:
            moveUp();
            break;

        case 2:
            moveDown();
            break;

        case 3:
            moveRight();

            break;

        case 4:
            moveLeft();
            break;
        }
    }
}
int winer()  // chacks if player have solved the puzzel
{
    int ans=0;
    for(int i = 0; i < arraySize; i++){
        for(int j = 0; j < arraySize; j++){
            if(homes[i][j] == check[i][j])
                ans = 1;
            else
                return -1;
        }
    }
    return ans;

}
int puzzlegame(int d)
{
    srand(time(0));
    randomise();
    char s[60];
    int b=0;
    do
    {
//        for(int i = 0; i < arraySize; i++){
//            for(int j = 0; j < arraySize; j++)
//                cout << "  " << homes[i][j];
//            cout << endl << endl;

//        }
        for(int i = 0; i < arraySize; i++){
            cout<<endl;
            for(int j = 0; j < arraySize; j++){
                cout <<left<<setw(2)<<" "<<left<<setw(5)<<homes[i][j]<<left<<setw(5)<<"*";
            }
            cout<<endl;
            cout<<"____________________________________________";
            cout<<endl<<endl;
        }
        char a;
        cout<<"teadad harekat:"<<b<<"/"<<d<<endl;
        cout << "w - Up, z - Down, a - Left, s - Right, u - Undo" << endl;
        cin >> a;
        s[b]=a;
        switch(a)
        {
        case 'W':
        case 'w':
            moveUp();
            b++;
            break;

        case 'Z':
        case 'z':
            moveDown();
            b++;
            break;
        case 's':
        case 'S':
            moveRight();
            b++;
            break;
        case 'a':
        case 'A':
            moveLeft();
            b++;
            break;
        case 'u':
        case 'U':
            undo(s,b);
            b--;
            break;
        default:
            cout << "Wrong character, pleas type again!" << endl;
            break;
        }
        int c = winer();
        if(c == 1){
            cout << "Bravo! You solved the puzle!" << endl;
            return 15;
        }
        system("cls");
    }while(b<=d);
    cout<<"__________________________________"<<endl;
    cout<<"|     ***              ***       |"<<endl;
    cout<<"|    ****** Game Over ******     |"<<endl;
    cout<<"|     ***              ***       |"<<endl;
    cout<<"|________________________________|"<<endl;
    int score=0;
    for(int i = 0; i < arraySize; i++)
        for(int j = 0; j < arraySize; j++)
            if(homes[i][j] == check[i][j])
                score++;
    return score;
}

#endif // BAZI_H

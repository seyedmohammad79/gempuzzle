#ifndef BAZI_H
#define BAZI_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "timer.h"

using namespace std;


const int arraySize1= 4;
const int arraySize2=3;
string homes1[ arraySize1 ] [ arraySize1 ] = {{"1","2","3","4"},
                                           {"5","6","7","8"},
                                           {"9","10","11","12"},
                                           {"13","14"," ","15"}};

string check1  [ arraySize1 ] [ arraySize1 ] = {{"1","2","3","4"},
                                             {"5","6","7","8"},
                                             {"9","10","11","12"},
                                             {"13","14"," ","15"}};
string homes2[ arraySize2 ] [ arraySize2 ] = {{"1","2","3"},
                                           {"4","5","6"},
                                           {"7"," ","8"}};
string check2  [ arraySize2 ] [ arraySize2 ] = {{"1","2","3"},
                                                {"4","5","6"},
                                                {"7"," ","8"}};


int vs1 = 3; // vertical space Position
int hs1 = 2; // h space Position
int vs2 = 2; // vertical space Position
int hs2 = 1; // h space Position


void moveUp1()
{
    int vp = vs1;
    if(vp + 1 < 4 && vp >= 0){

        homes1[vs1][hs1] = homes1[vs1 + 1][hs1];
        homes1[vs1 + 1][hs1] = ' ';
        vs1 += 1;
    }
}
void moveUp2()
{
    int vp = vs2;
    if(vp + 1 < 3 && vp >= 0){

        homes2[vs2][hs2] = homes2[vs2 + 1][hs2];
        homes2[vs2 + 1][hs2] = ' ';
        vs2 += 1;
    }
}
void moveDown1()
{
    int vp = vs1;
    if(vp + 1 <= 4 && vp > 0){

        homes1[vs1][hs1] = homes1[vs1 - 1][hs1];
        homes1[vs1 - 1][hs1] = ' ';
        vs1 -= 1;
    }
}
void moveDown2()
{
    int vp = vs2;
    if(vp + 1 <= 3 && vp > 0){

        homes2[vs2][hs2] = homes2[vs2 - 1][hs2];
        homes2[vs2 - 1][hs2] = ' ';
        vs2 -= 1;
    }
}
void moveRight1()
{
    int hp = hs1;
    if(hp + 1 <= 4 && hp > 0){

        homes1[vs1][hs1] = homes1[vs1][hs1 - 1];
        homes1[vs1][hs1 - 1] = ' ';
        hs1 -= 1;
    }
}
void moveRight2()
{
    int hp = hs2;
    if(hp + 1 <= 3 && hp > 0){

        homes2[vs2][hs2] = homes2[vs2][hs2 - 1];
        homes2[vs2][hs2 - 1] = ' ';
        hs2 -= 1;
    }
}
void moveLeft1()
{
    int hp = hs1;
    if(hp + 1 < 4 && hp >= 0){

        homes1[vs1][hs1] = homes1[vs1][hs1 + 1];
        homes1[vs1][hs1 + 1] = ' ';
        hs1 += 1;
    }
}
void moveLeft2()
{
    int hp = hs2;
    if(hp + 1 < 3 && hp >= 0){

        homes2[vs2][hs2] = homes2[vs2][hs2 + 1];
        homes2[vs2][hs2 + 1] = ' ';
        hs2 += 1;
    }
}
void undo1(char s[],int f){
    if(s[f-1]=='w' || s[f-1]=='W'){
        moveDown1();
        return;
    }
    if(s[f-1]=='z' || s[f-1]=='Z'){
        moveUp1();
        return;
    }
    if(s[f-1]=='a' || s[f-1]=='A'){
        moveRight1();
        return;
    }
    if(s[f-1]=='s' || s[f-1]=='S'){
        moveLeft1();
        return;
    }
    if(s[f-1]=='u' || s[f-1]=='U'){
        undo1(s,f-1);
    }
}
void undo2(char s[],int f){
    if(s[f-1]=='w' || s[f-1]=='W'){
        moveDown2();
        return;
    }
    if(s[f-1]=='z' || s[f-1]=='Z'){
        moveUp2();
        return;
    }
    if(s[f-1]=='a' || s[f-1]=='A'){
        moveRight2();
        return;
    }
    if(s[f-1]=='s' || s[f-1]=='S'){
        moveLeft2();
        return;
    }
    if(s[f-1]=='u' || s[f-1]=='U'){
        undo2(s,f-1);
    }
}
void randomise1() // randomize the array
{
    for(int i = 0; i < 20000; i++)
    {
        int a = 1 + rand() % 4;
        switch(a)
        {
        case 1:
            moveUp1();
            break;

        case 2:
            moveDown1();
            break;

        case 3:
            moveRight1();

            break;

        case 4:
            moveLeft1();
            break;
        }
    }
}
void randomise2() // randomize the array
{
    for(int i = 0; i < 20000; i++)
    {
        int a = 1 + rand() % 4;
        switch(a)
        {
        case 1:
            moveUp2();
            break;

        case 2:
            moveDown2();
            break;

        case 3:
            moveRight2();

            break;

        case 4:
            moveLeft2();
            break;
        }
    }
}
int winer1()  // chacks if player have solved the puzzel
{
    int ans=0;
    for(int i = 0; i < arraySize1; i++){
        for(int j = 0; j < arraySize1; j++){
            if(homes1[i][j] == check1[i][j])
                ans = 1;
            else
                return -1;
        }
    }
    return ans;

}
int winer2()  // chacks if player have solved the puzzel
{
    int ans=0;
    for(int i = 0; i < arraySize2; i++){
        for(int j = 0; j < arraySize2; j++){
            if(homes2[i][j] == check2[i][j])
                ans = 1;
            else
                return -1;
        }
    }
    return ans;

}
int puzzlegame(int d,int l)
{
    if(l==15){

        srand(time(0));
        randomise1();
        char s[60];
        int b=0;
        do
        {
            for(int i = 0; i < arraySize1; i++){
                cout<<endl;
                for(int j = 0; j < arraySize1; j++){
                    cout <<left<<setw(2)<<" "<<left<<setw(5)<<homes1[i][j]<<left<<setw(5)<<"*";
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
                moveUp1();
                b++;
                break;

            case 'Z':
            case 'z':
                moveDown1();
                b++;
                break;
            case 's':
            case 'S':
                moveRight1();
                b++;
                break;
            case 'a':
            case 'A':
                moveLeft1();
                b++;
                break;
            case 'u':
            case 'U':
                undo1(s,b);
                b--;
                break;
            default:
                cout << "Wrong character, pleas type again!" << endl;
                break;
            }
            int c = winer1();
            if(c == 1){
                cout << "Bravo! You solved the puzle!" << endl;
                return 15;
            }
            system("cls");
        }while(b<=d);
        int score=0;
        for(int i = 0; i < arraySize1; i++)
            for(int j = 0; j < arraySize1; j++)
                if(homes1[i][j] == check1[i][j])
                    score++;
        cout<<"__________________________________"<<endl;
        cout<<"|     ***              ***       |"<<endl;
        cout<<"|    ****** Game Over ******     |"<<endl;
        cout<<"|     ***              ***       |"<<endl;
        cout<<"|________________________________|"<<endl;
        return score;
    }
    if(l==8){
        srand(time(0));
        randomise2();
        char s[60];
        int b=0;
        do
        {
            for(int i = 0; i < arraySize2; i++){
                cout<<endl;
                for(int j = 0; j < arraySize2; j++){
                    cout <<left<<setw(2)<<" "<<left<<setw(5)<<homes2[i][j]<<left<<setw(5)<<"*";
                }
                cout<<endl;
                cout<<"________________________________";
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
                moveUp2();
                b++;
                break;

            case 'Z':
            case 'z':
                moveDown2();
                b++;
                break;
            case 's':
            case 'S':
                moveRight2();
                b++;
                break;
            case 'a':
            case 'A':
                moveLeft2();
                b++;
                break;
            case 'u':
            case 'U':
                undo2(s,b);
                b--;
                break;
            default:
                cout << "Wrong character, pleas type again!" << endl;
                break;
            }
            int c = winer2();
            if(c == 1){
                cout << "Bravo! You solved the puzle!" << endl;
                return 8;
            }
            system("cls");
        }while(b<=d);
        int score=0;
        for(int i = 0; i < arraySize2; i++)
            for(int j = 0; j < arraySize2; j++)
                if(homes2[i][j] == check2[i][j])
                    score++;
        cout<<"__________________________________"<<endl;
        cout<<"|     ***              ***       |"<<endl;
        cout<<"|    ****** Game Over ******     |"<<endl;
        cout<<"|     ***              ***       |"<<endl;
        cout<<"|________________________________|"<<endl;
        return score;
    }
    return 0;
}

#endif // BAZI_H

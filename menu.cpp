#include "menu.h"
#include<iostream>

using namespace std;

void welcome_message()
{
    cout << "________________________________________\n"
            "|              GEM PUZZLE              |\n"
            "|         welcome to this game         |\n"
            "________________________________________\n" ;
}
void help(){
    cout <<
    "________________________________________\n"
    "help           to get help             |\n"
    "adduser        to add a user           |\n"
    "enter          to sign in              |\n"
    "guest          to play as guest        |\n"
    "setting        to show setting         |\n"
    "jadval         to show score           |\n"
    "quit           to quit                 |\n"
    "________________________________________\n"
            ;
}
void settings(){
    cout<<
    "___________________________________________________________________\n"
    "   level     |     Tedad Harekat Mojaz  |    Time Mojaz (minutes)  |\n"
    "     1       |              60          |            10            |\n"
    "     2       |              55          |             9            |\n"
    "     3       |              50          |             8            |\n"
    "     4       |              45          |             7            |\n"
    "     5       |              40          |             6            |\n"
    "     6       |              35          |             5            |\n"
    "     7       |              30          |             4            |\n"
    "     8       |              25          |             3            |\n"
    "     9       |              20          |             2            |\n"
    "     10      |              15          |             1            |\n"
    "____________________________________________________________________\n"
           ;
}
zcommand getcommand(){
    cout <<"________________________________________\n";
    cout <<"enter command :" ;
    string cmd;
    cin>>cmd;
    if(cmd=="help")
        return _help;
    if(cmd=="adduser")
        return _add_user;
    if(cmd=="enter")
        return _enter;
    if(cmd=="setting")
        return _setting;
    if(cmd=="jadval")
        return _jadval_score;
    if(cmd=="guest")
        return _guest;
    if(cmd=="quit")
        return _quit;
    return _bad_command;
}

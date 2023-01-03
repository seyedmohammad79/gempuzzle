#ifndef MENU_H
#define MENU_H
#include<iostream>
using namespace std;

enum zcommand{
    _help,
    _add_user,
    _enter,
    _quit,
    _setting,
    _jadval_score,
    _guest,
    _bad_command
};

void welcome_message();
void help();
void settings();
zcommand getcommand();


#endif // MENU_H

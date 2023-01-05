#include "menu.h"
#include "login.h"
#include "carbar.h"
#include <iostream>

using namespace std;

int main()
{
    z_user b;
    welcome_message();
    help();
    settings();
    while(true){
        zcommand a=getcommand();
        switch (a) {
        case _help :        help();         break;
        case _setting:      settings();     break;
        case _add_user:     b.add_user();   break;
        case _enter:        b.sign_in();    break;
        case _guest:        b.guest();      break;
        case _jadval_score: b.jadval();     break;
        case _quit :        return 0;
        default:cout<<"bad command"<<endl;
        }
    }
    return 0;
}

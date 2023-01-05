#include "carbar.h"
#include "login.h"
#include "bazi.h"
#include "menu.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#define user_file "crbar.txt"

vector<string> split(const string &x,char d){
    string tmp;
    vector<string> r;
    for(unsigned int i=0;i<x.size();++i){
        if(x[i]==d){
            r.push_back(tmp);
            tmp.clear();
        }else tmp.push_back(x[i]);
    }
    r.push_back(tmp);
    return r;
}
void checkpass(string &s){
    int n = s.length();
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    for (int i = 0; i < n; i++) {
       if (islower(s[i]))
          hasLower = true;
       if (isupper(s[i]))
          hasUpper = true;
       if (isdigit(s[i]))
          hasDigit = true;
       size_t special = s.find_first_not_of(normalChars);
       if (special != string::npos)
          specialChar = true;
    }
    cout << "Strength of password:";
    if (hasLower && hasUpper && hasDigit &&
       specialChar && (n >= 8))
       cout << "Strong" << endl;
    else if ((hasLower || hasUpper) &&
       specialChar && (n >= 6))
       cout << "Moderate" << endl;
    else
       cout << "Weak" << endl;
}
int level_game(int n){
    int h;
    switch (n) {
    case 1: h=60;return h;
    case 2: h=55;return h;
    case 3: h=50;return h;
    case 4: h=45;return h;
    case 5: h=40;return h;
    case 6: h=35;return h;
    case 7: h=30;return h;
    case 8: h=25;return h;
    case 9: h=20;return h;
    case 10: h=15;return h;
    }
    return 60;
}
int time_game(int a){
    int b;
    switch (a) {
    case 60: b=10;   return b;
    case 55: b=9 ;   return b;
    case 50: b=8 ;   return b;
    case 45: b=7 ;   return b;
    case 40: b=6 ;   return b;
    case 35: b=5 ;   return b;
    case 30: b=4 ;   return b;
    case 25: b=3 ;   return b;
    case 20: b=2 ;   return b;
    case 15: b=1 ;   return b;
    }
    return 5;

}
z_user::z_user()
{
    ifstream userfile;
    userfile.open("user.txt");
    string a;
    string b;
    string c;
    string d;
    login us;
    while(userfile.good()){
        getline(userfile,a);
        istringstream s(a);
        s>>b>>c>>d;
        us.usern=b;
        us.pass=c;
        us.score=d;
        tb_user[b]=us;
    }
    userfile.close();
   // ifstream userfile("C:\\Users\\hoseini\\Documents\\puzzle\\user.txt");
//    if(userfile.is_open()){
//        while(!userfile.eof()){
//            string l;
//            getline(userfile,l);
//            if(l==" ")
//                return;
//            vector<string> res=split(l,' ');
//            for(auto x:res)
//                cout<<x<<endl;
//        }
//    }
}
void z_user::add_user()
{
//    ifstream userfile("C:\\Users\\hoseini\\Documents\\puzzle\\user.txt");
//    string a;
//    string b;
//    string c;
//    login us;
//    while(userfile.good()){
//        getline(userfile,a);
//        istringstream s(a);
//        s>>b>>c;
//        us.usern=b;
//        us.pass=c;
//        tb_user[b]=us;
//    }
    cout<<"username :";
    string u;
    cin.ignore();
    getline(cin,u);
    if(tb_user.find(u)!=tb_user.end()){
        cout<<"username tekrari"<<endl;
        return;
    }
    login user;
    user.usern=u;
    cout<<"enter password :";
    getline(cin,user.pass);
    checkpass(user.pass);
    tb_user[u]=user;
//    else{
//        for(auto x:tb_user){
//            login user=x.second;
//            us_file<<user.usern<< " " <<user.pass<<endl;
//            ;
//        }
//    }
    cout<<"please sign in to start game"<<endl;
}

void z_user::sign_in()
{
//    ifstream user("C:\\Users\\hoseini\\Documents\\puzzle\\user.txt");
//    string a;
//    string b;
//    string c;
//    login us;
//    while(user.good()){
//        getline(user,a);
//        istringstream s(a);
//        s>>b>>c;
//        us.usern=b;
//        us.pass=c;
//        tb_user[b]=us;
//    }
    cout<<"username :";
    string u;
    cin.ignore();
    getline(cin,u);
    if(tb_user.find(u)==tb_user.end()){
        cout<<"username dont exist"<<endl;
        return;
    }
    login z;
    z.usern=u;
    for(auto& it:tb_user){
        if(it.first==u)
            z=it.second;
    }
    cout<<z.pass<<endl;
    cout<<"password :";
    string w;
    getline(cin,w);
    //cout<<w<<endl;
    if(w!=(z.pass)){
        cout<<"wrong password"<<endl;
        return;
    }
    z.pass=w;
    cout<<" ***** start game ***** "<<endl;
    int n;
    cout<<endl;
    cout<<"choose level of game from 1 to 10 :"<<endl;
    cout<<endl;
    cout<<"Level : ";
    cin>>n;
    int a=level_game(n);
    cout<<endl;
    cout<<"tedad harekat mojaz : "<<a<<endl;
    int b=time_game(a);
    cout<<endl;
    cout<<"time mokaz : "<<b<<" "<<"minutes"<<endl;
    int score;
    score=puzzlegame(a);
    score=score*(n);
    cout<<"your score :"<<score<<endl;
    z.score=to_string(score);
    tb_user[u]=z;
    welcome_message();
    help();
}

void z_user::guest()
{
    cout<<" ****** start game ******"<<endl;
    int n;
    cout<<"choose level of game from 1 to 10 :"<<endl;
    cin>>n;
    int a=level_game(n);
    cout<<"tedad harekat mojaz : "<<a<<endl;
    int b=time_game(a);
    cout<<"time mokaz : "<<b<<" "<<"minutes"<<endl;
    puzzlegame(a);
}

void z_user::jadval()
{
    cout<<"________________________"<<endl;
    cout<<left<<setw(10)<<"Username"<<left<<setw(5)<<"|"<<left<<setw(10)<<"score"<<endl;
    cout<<"------------------------"<<endl;
    for(auto x:tb_user){
        login u=x.second;
        //cout<<"|"<<x.first<<"      "<<"| "<<u.score<<"|"<<endl;
        cout<<left<<setw(10)<<x.first<<left<<setw(5)<<"|"<<left<<setw(10)<<u.score<<endl;
    }
    cout<<"________________________"<<endl;
}

z_user::~z_user()
{
    ifstream user1;
    user1.open("user.txt");
    user1.close();
    remove("user.txt");
    ofstream user2;
    user2.open("user.txt",ios::app | ios::out);
    for(auto x:tb_user){
        login user=x.second;
        user2<<user.usern<< " " <<user.pass<<" "<<user.score<<endl;
        ;
    }

//    ofstream us_file("C:\\Users\\hoseini\\Documents\\puzzle\\user.txt",ios_base::app);
//    us_file.clear();
//    if(!us_file.is_open()){
//        cout << " ************cant write username file************** " << endl ;
//    }else{
//        for(auto x:tb_user){
//          login user=x.second;
//            us_file<<user.usern<< " " <<user.pass<<" "<<user.score<<endl;
//            ;
//        }
//    }
}

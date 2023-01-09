#ifndef CARBAR_H
#define CARBAR_H
#include "login.h"
#include <map>
class z_user{
    map<string /*user name*/,login> tb_user;
public:
    z_user();
    void add_user();
    void sign_in();
    void guest();
    void jadval();
    void pass();
    ~z_user();
};

#endif // CARBAR_H

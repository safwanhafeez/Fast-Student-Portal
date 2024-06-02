#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
    protected:
        string usr;
        string pwd;
        string email;

    public:
        User();
        User(string u, string p);
        void setUsr(string u);
        void setPwd(string pwd);
        string getUsr();
        string getPwd();
};

#endif // USER_H
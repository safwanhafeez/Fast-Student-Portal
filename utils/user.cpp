#include "../include/user.h"

User::User() {
    usr = "";
    pwd = "";
}
User::User(string u, string p) {
    usr = u;
    pwd = p;
}
void User::setUsr(string u) {
    this->usr = u;
}
void User::setPwd(string pwd) {
    this->pwd = pwd;
}
string User::getUsr() {
    return usr;
}
string User::getPwd() {
    return pwd;
}
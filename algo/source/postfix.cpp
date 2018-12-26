#include"../includes/postfix.h"
#include<iostream>

postfix::postfix (int ss) {
    size = ss;
    n = 0;
    s = new char[size];
    ans = 0;
}

void postfix::push (char &t) {
    if (n == size) throw "Queue owerflow";
    s[n++] = t;
}

bool postfix::empty () {
    return (n == 0);
}
char postfix::pop () {
    if (n == 0) throw "Queue is empty";
    return s[--n];
}
void postfix::print () {
    std::cout << std::endl;
    while (!empty()) {
        std::cout << pop ();
    }
    std::cout << std::endl;
}
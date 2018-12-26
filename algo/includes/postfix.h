#pragma once

class postfix {
    char* s;
    int n;
    int size;
public:
    int ans;
    postfix (int ss = 1000);
    int get_ans ();
    void push (char &t);
    bool empty ();
    char pop ();
    void print ();
};
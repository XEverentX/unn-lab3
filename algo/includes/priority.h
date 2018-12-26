#pragma once

class priority {
    char* c;
    int* p;
    int n;
    int size;
public:
    priority (int ssize = 20) {
        c = new char [ssize];
        p = new int [ssize];
        size = ssize;
        n = 0;
    }
    void add (char cc, int pp) {
        if (size <= n) throw "Priority overflow";
        c[n] = cc;
        p[n++] = pp;
    }

    int get (char cc) {
        for (int i = 0; i < n; i++) {
            if (c[i] == cc) return p[i];
        }
        throw "Have no any operation like that, sorry";
    }

    bool is (char t) {
        for (int i = 0; i < n; i++) {
            if (c[i] == t) return true;
        }
        return false;
    }
};

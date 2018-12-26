#include<iostream>
#include"../includes/Stack.h"

stack::stack (int ssize) {
    size = ssize;
    n = 0;
    p = new char [size];
}

void stack::push (char x) {
    if (n >= size) throw "Stack overflow";
    p[n++] = x;
}

char stack::pop () {
    if (n <= 0) throw "Stack is empty, but you still try";
    return p[--n];
}

char stack::front() {
    if (n <= 0) throw "Stack is empty, but you still try";
    return p[n - 1];
}

int stack::getn () {
    return n;
}

bool stack::empty() {
    return n == 0;
}


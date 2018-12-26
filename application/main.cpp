#include<iostream>
#include<string.h>
#include<stdio.h>
#include"../algo/includes/Stack.h"
#include"../algo/includes/help_funk.h"
#include"../algo/includes/priority.h"
#include"../algo/includes/postfix.h"
#include"../algo/includes/calc.h"

int main() {
    char *s = new char[1000];
    std::cin >> s;
    try {
        postfix res = calc (s);
        std::cout << std::endl << res.ans << std::endl;
        res.print ();
    } catch (char* er) {
        std::cout << er << std::endl;
    }
}

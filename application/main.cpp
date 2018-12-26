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
    std::cout << "\nHi! Enter the string.\n";
    std::cout << "String may consist of numbers (int), whitespaces and operations (+ - * / ^ ( ) )\n\n";
    std::cin.getline (s, 1000);
    try {
        postfix res = calc (s);
        std::cout << "\nСalculated Answer: " << res.ans << std::endl;
        res.print ();
    } catch (char* er) {
        std::cout << "Postfix string: " << er << std::endl;
    }
}

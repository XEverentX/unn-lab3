#include<iostream>

int operate (int a, int b, char g){
    switch (g) {
        case '+':
            a += b;
            break;
        case '-':
            a -= b;
            break;
        case '*':
            a *= b;
            break;
        case '/':
            if (b == 0) throw " a / 0 -> inf, but not there";
            a /= b;
            break;
        case '^': 
            int me = a;
            a = 1;
            for (int i = 0; i < b; i++) {
                a *= me;
            }
            break;
        /*default:
            throw "I don't relese this operation, sorry";*/
    }
    return a;
}

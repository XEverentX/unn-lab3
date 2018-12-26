#include"../includes/Stack.h"
#include"../includes/help_funk.h"
#include"../includes/priority.h"
#include"../includes/postfix.h"
#include<string.h>

postfix calc (char* s) {
    int n = strlen (s);

    priority pr (7);
    pr.add ('+', 1);
    pr.add ('-', 1);
    pr.add ('*', 2);
    pr.add ('/', 2);
    pr.add ('^', 3);
    pr.add ('(', 0);
    pr.add (')', 0);

    stack st (n);
    postfix res (n);
    int index = 0;
    int* v = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int r = 1;
            int ans = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                res.push (s[i]);
                ans += r * (s[i++] - '0');
                r *= 10;
            }
            r /= 10;
            v[j] = 0;
            while (ans) {
                v[j] += (ans % 10) * r;
                ans /= 10;
                r /= 10;
            }
            j++;
        }
        if (i >= n) break;
        if (s[i] == '(') {
            st.push ('(');
            continue;
        }
        if (s[i] == ')') {
            if (st.getn() == 0) throw "Stack is empty";
            char g = st.pop();
            while (g != '(') {
                if (st.getn() == 0) throw "Stack is empty";
                if (j <= 1) throw "Few arguments";
                res.push (g);
                v[j - 2] = operate (v[j - 2], v[j - 1], g);
                j--;
                g = st.pop();
            }
            continue;
        }
        if (s[i] == ' ') continue;
        if (pr.is (s[i])) {
            while (!st.empty() && (pr.get (st.front()) >= pr.get (s[i]))) {
                if (j <= 1) throw "Few arguments";
                char g = st.pop ();
                res.push (g);
                v[j - 2] = operate (v[j - 2], v[j - 1], g);
                j--;
            }
            st.push (s[i]);
            continue;
        }
        throw "You write strange thing";
    }
    while (!st.empty()) {
        if (j <= 1) throw "Few arguments";
        char g = st.pop ();
        res.push (g);
        v[j - 2] = operate (v[j - 2], v[j - 1], g);
        j--;
    }
    res.ans = v[0];
    return res;
}
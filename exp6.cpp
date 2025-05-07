#include <bits/stdc++.h>
using namespace std;

void show(stack<string> s, vector<string>& in, int i, string a) {
    stack<string> t;
    while (!s.empty()) t.push(s.top()), s.pop();
    while (!t.empty()) cout << t.top(), t.pop();
    cout << "\t";
    while (i < in.size()) cout << in[i++];
    cout << "\t" << a << "\n";
}

int main() {
    vector<string> in = {"id", "+", "id", "*", "id", "$"};
    stack<string> s;
    int i = 0;
    cout << "STACK\tINPUT\tACTION\n";
    while (i < in.size() || s.size() > 2 || (s.size() == 2 && s.top() != "$")) {
        if (i < in.size()) s.push(in[i++]), show(s, in, i, "Shift");
        while (s.size()) {
            if (s.size() > 2) {
                string a = s.top(); s.pop();
                string b = s.top(); s.pop();
                string c = s.top(); s.pop();
                if (c == "E" && b == "+" && a == "E") s.push("E"), show(s, in, i, "Reduce:E->E+E");
                else if (c == "E" && b == "*" && a == "E") s.push("E"), show(s, in, i, "Reduce:E->E*E");
                else if (c == "(" && b == "E" && a == ")") s.push("E"), show(s, in, i, "Reduce:E->(E)");
                else s.push(c), s.push(b), s.push(a);
            }
            if (s.size() && s.top() == "id") s.pop(), s.push("E"), show(s, in, i, "Reduce:E->id");
            else break;
        }
    }
    show(s, in, i, "Accept");
}

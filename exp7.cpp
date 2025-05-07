#include <bits/stdc++.h>
using namespace std;
struct Production {
    string lhs;
    vector<string> rhs; 
};
string setToString(const set<string>& s) {
    string res;
    for (const auto& x : s) res += x + ",";
    return res.empty() ? "{}" : "{" + res.substr(0, res.size() - 1) + "}";
}
void show(string nt, const set<string>& lead, const set<string>& trail, string action) {
    cout << nt << "\t" << setToString(lead) << "\t" << setToString(trail) << "\t" << action << "\n";
}
int main() {
    vector<Production> grammar = {
        {"E", {"E", "+", "T"}}, {"E", {"T"}},
        {"T", {"T", "*", "F"}}, {"T", {"F"}},
        {"F", {"(", "E", ")"}}, {"F", {"id"}}
    };
    set<string> nonTerminals = {"E", "T", "F"};
    set<string> terminals = {"id", "+", "*", "(", ")"};
    map<string, set<string>> leading, trailing;
    for (const auto& nt : nonTerminals) {
        leading[nt] = {};
        trailing[nt] = {};
    }
    cout << "Non-Terminal\tLeading\tTrailing\tAction\n";
    bool changed = true;
    while (changed) {
        changed = false;
        for (const auto& prod : grammar) {
            string A = prod.lhs;
            const auto& alpha = prod.rhs;
            string first = alpha[0];
            if (terminals.count(first)) {
                if (leading[A].insert(first).second) {
                    show(A, leading[A], trailing[A], "Add " + first + " to Leading(" + A + ")");
                    changed = true;
                }
            } else if (nonTerminals.count(first)) {
                for (const auto& t : leading[first]) {
                    if (leading[A].insert(t).second) {
                        show(A, leading[A], trailing[A], "Add " + t + " from Leading(" + first + ") to Leading(" + A + ")");
                        changed = true;
                    }
                }
            }
            string last = alpha.back();
            if (terminals.count(last)) {
                if (trailing[A].insert(last).second) {
                    show(A, trailing[A], leading[A], "Add " + last + " to Trailing(" + A + ")");
                    changed = true;
                }
            } else if (nonTerminals.count(last)) {
                for (const auto& t : trailing[last]) {
                    if (trailing[A].insert(t).second) {
                        show(A, trailing[A], leading[A], "Add " + t + " from Trailing(" + last + ") to Trailing(" + A + ")");
                        changed = true;
                    }
                }
            }
        }
    }
    cout << "\nFinal Sets:\n";
    for (const auto& nt : nonTerminals) {
        show(nt, leading[nt], trailing[nt], "Final");
    }
}

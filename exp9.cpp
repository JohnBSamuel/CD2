#include <iostream>
#include <stack>
#include <string>

using namespace std;

int tempCount = 1;

string newTemp() {
    return "t" + to_string(tempCount++);
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void generateFromPrefix(const string& expr) {
    stack<string> st;
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            st.push(string(1, c));
        } else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = newTemp();
            cout << temp << " = " << op1 << " " << c << " " << op2 << endl;
            st.push(temp);
        }
    }
}

void generateFromPostfix(const string& expr) {
    stack<string> st;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            st.push(string(1, c));
        } else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = newTemp();
            cout << temp << " = " << op1 << " " << c << " " << op2 << endl;
            st.push(temp);
        }
    }
}

int main() {
    string prefix = "*+AB-CD";
    string postfix = "AB+CD-*";
    
    cout << "Three-address code for prefix: " << prefix << endl;
    generateFromPrefix(prefix);

    tempCount = 1; // Reset for postfix
    cout << "\nThree-address code for postfix: " << postfix << endl;
    generateFromPostfix(postfix);

    return 0;
}

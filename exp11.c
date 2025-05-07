#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateMachineCode(string statement) {
    vector<string> code;
    stringstream ss(statement);
    string a, eq, b, op, c;

    ss >> a >> eq >> b >> op >> c;

    if (eq == "=" && op == "+") {
        code.push_back("LOAD " + b);
        code.push_back("ADD " + c);
        code.push_back("STORE " + a);
    } else if (eq == "=" && op == "-") {
        code.push_back("LOAD " + b);
        code.push_back("SUB " + c);
        code.push_back("STORE " + a);
    } else if (eq == "=" && op == "*") {
        code.push_back("LOAD " + b);
        code.push_back("MUL " + c);
        code.push_back("STORE " + a);
    } else if (eq == "=" && op == "/") {
        code.push_back("LOAD " + b);
        code.push_back("DIV " + c);
        code.push_back("STORE " + a);
    } else {
        code.push_back("Error: Unsupported operation");
    }

    return code;
}

int main() {
    string statement;
    cout << "Enter a statement (e.g., a = b + c): ";
    getline(cin, statement);

    vector<string> machineCode = generateMachineCode(statement);

    cout << "\nGenerated Machine Code:\n";
    for (const string& line : machineCode) {
        cout << line << endl;
    }

    return 0;
}

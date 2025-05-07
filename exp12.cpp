#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Instruction {
    string op, arg1, arg2, result;
    Instruction(string o, string a1 = "", string a2 = "", string res = "")
        : op(o), arg1(a1), arg2(a2), result(res) {}
};

vector<Instruction> instructions;

int generate(const string& op, const string& a1 = "", const string& a2 = "", const string& res = "") {
    instructions.emplace_back(op, a1, a2, res);
    return instructions.size() - 1;
}

vector<int> makelist(int i) { return {i}; }

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> out = a;
    out.insert(out.end(), b.begin(), b.end());
    return out;
}

void backpatch(const vector<int>& list, int target) {
    for (int i : list) instructions[i].result = to_string(target);
}

void printInstructions() {
    for (size_t i = 0; i < instructions.size(); ++i)
        cout << i << ": " << instructions[i].op << " " << instructions[i].arg1 << " "
             << instructions[i].arg2 << " " << instructions[i].result << "\n";
}

int main() {
    vector<int> falselist = makelist(generate("if-false", "a < b"));
    vector<int> truelist = makelist(generate("goto"));
    
    int trueBlock = generate("label", "TrueBlockStart");
    int falseBlock = generate("print", "False Block");

    backpatch(falselist, falseBlock);
    backpatch(truelist, instructions.size());

    printInstructions();
    return 0;
}

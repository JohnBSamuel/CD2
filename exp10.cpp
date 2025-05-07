#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Quadruple structure
struct Quadruple {
    string op, arg1, arg2, result;
};

// Triple structure
struct Triple {
    string op, arg1, arg2;
};

int main() {
    // Sample Quadruples
    vector<Quadruple> quadruples = {
        {"+", "b", "c", "t1"},
        {"*", "t1", "d", "t2"},
        {"-", "t2", "e", "t3"},
        {"=", "t3", "", "a"}
    };

    cout << "QUADRUPLES:\n";
    cout << "Op\tArg1\tArg2\tResult\n";
    for (const auto& q : quadruples) {
        cout << q.op << "\t" << q.arg1 << "\t" << q.arg2 << "\t" << q.result << endl;
    }

    // Sample Triples
    vector<Triple> triples = {
        {"+", "b", "c"},
        {"*", "(0)", "d"},
        {"-", "(1)", "e"},
        {"=", "(2)", "a"}
    };

    cout << "\nTRIPLES:\n";
    cout << "Index\tOp\tArg1\tArg2\n";
    for (size_t i = 0; i < triples.size(); ++i) {
        cout << i << "\t" << triples[i].op << "\t" << triples[i].arg1 << "\t" << triples[i].arg2 << endl;
    }

    // Indirect Triples (Pointer Table to Triples)
    vector<int> pointerTable = {0, 1, 2, 3};

    cout << "\nINDIRECT TRIPLES (Pointer Table):\n";
    for (size_t i = 0; i < pointerTable.size(); ++i) {
        int index = pointerTable[i];
        const Triple& t = triples[index];
        cout << i << "\t(" << t.op << ", " << t.arg1 << ", " << t.arg2 << ")\n";
    }

    return 0;
}

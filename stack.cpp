#include <iostream>
#include <string>
using namespace std;

const int N = 100001;

string Stack[N];
int n, top = 1;


void push(string name) {
    Stack[top] = name;
    top += 1;
}

string pop() {
    top -= 1;
    return Stack[top];
}

string query(int pos) {
    return Stack[pos];
}

int main() {
    int n;
    cin >> n;
    char name[20];
    for (; n--; ) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> name;
            push(name);
        } else if (op == 2) {
            cout << pop() << endl;
        } else {
            int pos;
            cin >> pos;
            cout << query(pos) << endl;
        }
    }
    return 0;
}

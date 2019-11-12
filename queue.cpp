#include <iostream>
#include <string>
using namespace std;

const int N = 100001;
string Queue[N];
int head = 1, tail = 1;

void enqueue(string name) {
  Queue[tail++] = name;
}

string dequeue() {
  return Queue[head++];
}

string query(int pos) {
  return Queue[head + pos - 1];
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
            enqueue(name);
        } else if (op == 2) {
            cout << dequeue() << endl;
        } else {
            int pos;
            cin >> pos;
            cout << query(pos) << endl;
        }
    }
    return 0;
}

#include "stdio.h"
#include <vector>
using namespace std;

typedef long long ll;

const int Mod = 100003;
vector<ll> table[Mod];

int Hash(ll x) {
    return x % Mod;
}

bool check(int op, ll x) {
    int h = Hash(x);

    vector<ll>::iterator p = table[h].end();
    for (vector<ll>::iterator it = table[h].begin(); it != table[h].end(); it++) {
        if (*it == x) {
            p = it;
            break;
        }
    }

    if (op == 1) {
        if (p == table[h].end()) {
            table[h].push_back(x);
            return true;
        }
    }

    if (op == 2) {
        if (p != table[h].end()) {
            *p = table[h].back();
            table[h].pop_back();
            return true;
        }
    }
    return false;
}

int main() {
    int Q, op;
    ll x;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%lld", &op, &x);
        puts(check(op, x) ? "Succeeded" : "Failed");
    }
    return 0;
}

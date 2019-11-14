#include "stdio.h"
using namespace std;

typedef long long ll;

ll arr[500005];
int cnt = 0;

bool check(int op, ll x) {
    if (op == 1) {
        bool found = false;
        for (int i = 0; i < cnt; i++) {
            if (arr[i] == x) { found = true; break; }
        }
        if (!found) {
          arr[cnt++] = x;
          return true;
        }
    }

    if (op == 2) {
        bool found = false;
        int i = 0;
        for (i = 0; i < cnt; i++) {
            if (arr[i] == x) { found = true; break; }
        }
        if (found) {
            cnt--;
            for (int j = i; j < cnt; j++) {
              arr[j] = arr[j+1];
            }
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

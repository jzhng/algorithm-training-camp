#include "stdio.h"
#include <vector>
using namespace std;

const int N  = 500005;
struct UnionSet {
    int f[N];

    void init(int n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : (f[x] = find(f[x]));
    }

    bool merge(int x, int y) {
        int setX = find(x);
        int setY = find(y);
        if (setX == setY) {
            return false;
        }

        f[setX] = setY;
        return true;
    }
} us;

vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V) {
    vector<int> res;
    us.init(n);
    for (int i = m - 1; i >= 0; i--) {
        if (us.merge(U[i], V[i])) {
            res.push_back(i + 1);
        }
    }

    for (int i = 0, j = res.size() - 1; i < j; i++, j--) {
        swap(res[i], res[j]);
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> U, V;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        U.push_back(u);
        V.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, U, V);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d\n", ans[i]);
    return 0;
}

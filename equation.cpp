#include "stdio.h"
#include <string>
#include <vector>

using namespace std;

const int N = 300005;

int Father[N], Rank[N];
int find(int x) {
    return Father[x] == x ? x : (Father[x] = find(Father[x]));
}

string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {
    for (int i = 1; i <= n; i++) {
        Father[i] = i;
        Rank[i] = 0;
    }

    for (int i = 0, j = m - 1; i < j;) {
        if (E[i] == 1) {
            i++;
        } else if (E[j] == 0) {
            j--;
        } else {
            swap(A[i], A[j]);
            swap(B[i], B[j]);
            swap(E[i], E[j]);
        }
    }

    for (int i = 0; i < m; i++) {
        int setA = find(A[i]);
        int setB = find(B[i]);
        if (E[i] == 0) {
            if (setA == setB) return "No";
        } else {
            if (setA != setB) {
                if (Rank[setA] > Rank[setB]) {
                    Father[setB] = setA;
                } else {
                    Father[setA] = setB;
                }

                if (Rank[setA] == Rank[setB]) {
                   Rank[setA]++;
                }
            }
        }
    }
    return "Yes";
}

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> A, B, E;
        for (int i = 0; i < m; ++i) {
            int a, b, e;
            scanf("%d%d%d", &a, &b, &e);
            A.push_back(a);
            B.push_back(b);
            E.push_back(e);
        }
        printf("%s\n", getAnswer(n, m, A, B, E).c_str());
    }
    return 0;
}

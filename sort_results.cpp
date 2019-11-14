#include "stdio.h"
#include <vector>
using namespace std;

vector<int> getAnswer(int n, vector<int> A, vector<int> DS) {
    vector<int> sum, id;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        id.push_back(i + 1);
        sum.push_back(A[i] + DS[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            if (sum[j] > sum[j-1] || (sum[j] == sum[j-1] && A[j] > A[j-1])) {
                swap(id[j], id[j-1]);
                swap(sum[j], sum[j-1]);
                swap(A[j], A[j-1]);
                swap(DS[j], DS[j-1]);
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        res.push_back(id[i]);
        res.push_back(sum[i]);
        res.push_back(A[i]);
        res.push_back(DS[i]);
    }
    res.push_back(cnt);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> A, DS;
    for (int i = 0; i < n; ++i) {
        int a, ds;
        scanf("%d%d", &a, &ds);
        A.push_back(a);
        DS.push_back(ds);
    }
    vector<int> ans = getAnswer(n, A, DS);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d %d\n", ans[cnt], ans[cnt + 1], ans[cnt + 2], ans[cnt + 3]);
        cnt += 4;
    }
    printf("%d\n", ans[cnt]);
    return 0;
}

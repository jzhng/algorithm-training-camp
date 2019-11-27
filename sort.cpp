#include "stdio.h"
#include <vector>
using namespace std;

void qsort(int l, int r, vector<int> &a) {
    if (l >= r) return;
    int i = l, j = r + 1;
    int key = a[l];
    while (true) {
        while (a[++i] < key && i < r) ;
        while (a[--j] > key && j > l) ;
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    qsort(l, j - 1, a);
    qsort(j + 1, r, a);
}

vector<int> getAnswer(int n, vector<int> &a) {
    qsort(0, n - 1, a);
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    a = getAnswer(n, a);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}

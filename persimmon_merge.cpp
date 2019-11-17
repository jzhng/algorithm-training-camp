#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

const int N = 10005;
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

class Edge {
public:
    Edge(int nodeX = 0, int nodeY = 0, int weight = 0);
    int x;
    int y;
    int w;
    bool selected;
};

Edge::Edge(int nodeX, int nodeY, int weight) {
    x = nodeX;
    y = nodeY;
    w = weight;
    selected = false;
}

void swapE(int i, int j, vector<Edge> &E) {
    swap(E[i].x, E[j].x);
    swap(E[i].y, E[j].y);
    swap(E[i].w, E[j].w);
    swap(E[i].selected, E[j].selected);
}

void qsort(int l, int r, vector<Edge> &E) {
    if (l >= r) return;
    int i = l, j = r + 1;
    int key = E[l].w;
    while (true) {
        while (E[++i].w < key && i < r) ;
        while (E[--j].w > key && j > l) ;
        if (i >= j) break;
        swapE(i, j, E);
    }
    swapE(l, j, E);
    qsort(l, j - 1, E);
    qsort(j+1, r, E);
}

int getAnswer(int n, int m, int k, vector<Edge> E) {
    int res = 0;

    us.init(n);

    qsort(0, m - 1, E);

    int j = 0;
    for (int i = 0; i < m; i++) {
        if (us.merge(E[i].x, E[i].y)) {
            E[i].selected = true;
            j++;
        }
        if (j == n - k) break;
    }

    if (j == n - k) {
        for (int i = 0; i < m; i++) {
            if (E[i].selected) {
                res += E[i].w;
            }
        }
        return res;
    }

    return -1;
}

int main()
{
    int n, m, k;
    vector<Edge> E;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E.push_back(Edge(u, v, w));
    }
    cout << getAnswer(n, m, k, E) << endl;
    return 0;
}

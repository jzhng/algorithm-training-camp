#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

struct node {
    int val, l, r;
} t[N];

int root, cnt;

int insert(int v, int x) {
    if (x == 0 && !t[x].val) {
      t[x].val = v;
      return 0;
    }

    if (v > t[x].val) {
      if (!t[x].r) {
        t[x].r = ++cnt;
        t[cnt].val = v;
      } else {
        insert(v, t[x].r);
      }
    } else {
      if (!t[x].l) {
        t[x].l = ++cnt;
        t[cnt].val = v;
      } else {
        insert(v, t[x].l);
      }
    }
    return x;
}

void dlr(int x, vector<int> &ans) {
    ans.push_back(t[x].val);
    if (t[x].l) dlr(t[x].l, ans);
    if (t[x].r) dlr(t[x].r, ans);
}

void lrd(int x, vector<int> &ans) {
    if (t[x].l) lrd(t[x].l, ans);
    if (t[x].r) lrd(t[x].r, ans);
    ans.push_back(t[x].val);
}

vector<int> getAnswer(int n, vector<int> sequence) {
    root = cnt  = 0;
    for (int i = 0; i < int(sequence.size()); i++) {
      insert(sequence[i], root);
    }

    vector<int> res;
    dlr(root, res);
    lrd(root, res);

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sequence.push_back(x);
    }
    vector<int> ans = getAnswer(n, sequence);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i)
        cout << ans[n + i] << " \n"[i == n - 1];
    return 0;
}

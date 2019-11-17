#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> getAnswer(int n, vector<int> A) {
    vector<int> ans;
    list<int> l;

    int *maxElement = new int[n]();
    maxElement[n-1] = A[n-1];
    for (int i = n - 2; i >= 0; i--) {
      maxElement[i] = max(maxElement[i+1], A[i]);
    }

    for (int i = 0; i < n; ) {
      int mx = maxElement[i];
      if (!l.empty() && A[l.front()] > mx && A[l.back()] > mx) {
        if (A[l.front()] > A[l.back()]) {
          ans.push_back(A[l.front()]);
          l.pop_front();
        } else {
          ans.push_back(A[l.back()]);
          l.pop_back();
        }
      } else if (!l.empty() && A[l.front()] > mx) {
          ans.push_back(A[l.front()]);
          l.pop_front();
      } else if (!l.empty() && A[l.back()] > mx) {
          ans.push_back(A[l.back()]);
          l.pop_back();
      } else {
        while (mx != A[i]) {
          l.push_back(i);
          i++;
        }
        ans.push_back(A[i]);
        i++;
      }
    }

    while (!l.empty()) {
      if (A[l.front()] > A[l.back()]) {
        ans.push_back(A[l.front()]);
        l.pop_front();
      } else {
        ans.push_back(A[l.back()]);
        l.pop_back();
      }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    vector<int> ans = getAnswer(n, a);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i-1] << " \n"[i == n];
    }
    return 0;
}

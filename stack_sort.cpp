#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> sorting(stack<int>);

int main() {
    int n;
    cin >> n;
    stack<int> myStack;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        myStack.push(tmp);
    }
    stack<int> result = sorting(myStack);
    vector<int> answer;
    while (!result.empty()) {
        answer.push_back(result.top());
        result.pop();
    }
    for (auto i = answer.rbegin(); i != answer.rend(); ++i)
        cout << *i << endl;
    return 0;
}

stack<int> sorting(stack<int> s) {
    stack<int> r;
    if (s.empty()) {
      return r;
    }

    int v = s.top();
    s.pop();
    while (!s.empty() || (!r.empty() && r.top() > v)) {
      if (r.empty() || r.top() <= v) {
        r.push(v);
        v = s.top();
        s.pop();
      } else {
        s.push(r.top());
        r.pop();
      }
    }
    r.push(v);

    return r;
}

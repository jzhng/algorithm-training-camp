#include <iostream>
#include <stack>
using namespace std;

int getAnswer(int n, int *height) {
    int res = 0;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n + 1; i++) {
        while (height[s.top()] > height[i]) {
            int h = height[s.top()];
            s.pop();
            res = max(res, h * (i - s.top() - 1));
        }
        s.push(i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int* height = new int[n + 2]();

    for (int i = 1; i <= n; ++i)
        cin >> height[i];

    cout << getAnswer(n, height) << endl;

    delete[] height;
    return 0;
}

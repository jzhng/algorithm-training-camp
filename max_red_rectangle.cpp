#include <iostream>
#include <stack>
using namespace std;

int getAnswer(int n, int m, string *matrix) {
    int res = 0;
    int *height = new int[m + 2]();
    stack<int> s;

    for (int k = 0; k < n; k++) {
        for (int i = 1; i <= m; i++) {
            if (matrix[k][i-1] == '.')
                height[i]++;
            else
                height[i] = 0;
        }

        while (!s.empty()) s.pop();
        s.push(0);

        for (int i = 1; i <= m + 1; i++) {
            while (height[s.top()] > height[i]) {
                int h = height[s.top()];
                s.pop();
                res = max(res, h * (i - s.top() - 1));
            }
            s.push(i);
        }
    }

    delete[] height;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    string *matrix = new string[n]();
    
    for (int i = 0; i < n; ++i)
        cin >> matrix[i];
    
    cout << getAnswer(n, m, matrix) << endl;
    
    delete[] matrix;
    return 0;
}

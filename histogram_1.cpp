#include <iostream>
using namespace std;

int getAnswer(int n, int *height) {
    int res = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int h = 5000;
            for (int c = a; c <= b; c++) {
                h = min(h, height[c]);
            }
            res = max(res, (b - a + 1) * h);
        }
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

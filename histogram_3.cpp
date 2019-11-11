#include <iostream>
using namespace std;

int getAnswer(int n, int *height) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && height[l] >= height[i]) l--;
        while (r <= n + 1 && height[r] >= height[i]) r++;
        res = max(res, (r - l - 1) * height[i]);
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

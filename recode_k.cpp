#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

priority_queue< ll, vector<ll>, greater<ll> > pq;

ll solve(int n, int k) {
    ll sum = 0;

    if (k != 2) {
        int r =  n % (k - 1) == 1 ? 0 : k - n % (k - 1);
        n += r;
        while (r--) pq.push(0);
    }

    while (n > 1) {
        ll newEle = 0;
        for (int i = 0; i < k; i++) {
            newEle += pq.top();
            pq.pop();
        }
        sum += newEle;
        pq.push(newEle);

        n -= (k - 1);
    }
    return sum;
}


int main() {
	int n, k;
  cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll a;
    cin >> a;
    pq.push(a);
	}
		
  cout << solve(n, k) << endl;
	return 0;
}

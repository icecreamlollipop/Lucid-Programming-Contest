
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long ans[101];
	for (int i=0;i<100;i++) ans[i] = LLONG_MAX;
	for (long long m=2; m<1000; m++) {
		for (long long n=2;n<1000;n++) {
			long long numer = 200*(m+n-2);
			long long denom = m*n;
			long long k = numer/denom;
			if (numer%denom==0) ans[k] = min(ans[k], denom);
		}
	}
	int k; cin >> k;
	cout << ans[k] << endl;
}

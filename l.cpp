
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int vals[n];
	int left[n];
	int right[n];
	for (int i=0;i<n;i++) cin >> vals[i];
	left[0] = vals[0];
	for (int i=1;i<n;i++) left[i] = max(left[i-1], vals[i]);
	right[n-1] = vals[n-1];
	for (int i=n-2;i>=0;i--) right[i] = max(right[i+1], vals[i]);
	long long ans = 0;
	for (int i=1;i<n-1;i++) {
		int add = min(left[i-1],right[i+1])-vals[i];
		if (add>0) ans += add;
	}
	cout << ans << endl;
}

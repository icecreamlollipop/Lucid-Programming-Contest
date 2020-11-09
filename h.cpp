
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long ans = LLONG_MAX;
	for (int i=0;i<n;i++) {
		long long a,b;
		cin >> a >> b;
		ans = min(ans, b/a);
	}
	cout << ans << endl;
}

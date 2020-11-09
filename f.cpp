
#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K; cin >> K;
	int arr[K][2];
	for (int a=0;a<2;a++) for (int d=0;d<K;d++) cin >> arr[d][a];
	long long dp[K+1][2];
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int d=0;d<K;d++) {
		for (int a=0;a<2;a++) {
			int b = 1-a;
			dp[d+1][a] = dp[d][a]+arr[d][a];
			if (d>0) dp[d+1][a] = max(dp[d+1][a], dp[d][b]);
		}
	}
	cout << max(dp[K][0], dp[K][1]) << endl;
}

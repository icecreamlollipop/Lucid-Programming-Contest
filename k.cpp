#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	string things[n];
	for (int i=0;i<n;i++) cin >> things[i];
	int votes[n];
	for (int i=0;i<n;i++) votes[i] = 0;
	int m; cin >> m;
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			string s;
			cin >> s >> s;
			if (s[0]=='y') votes[j] += 1;
			if (s[0]=='n') votes[j] -= 2;
		}
	}
	for (int i=0;i<n;i++) {
		cout << things[i] << ' ';
		if (votes[i]>0) cout << "yes\n";
		else if (votes[i]<0) cout << "no\n";
		else cout << "abstain\n";
	}
}

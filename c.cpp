
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	s = "-"+s+"-";
	int n = s.size();
	int next[n];
	int prev[n];
	for (int i=0;i<n;i++) {
		next[i] = i+1;
		prev[i] = i-1;
	}
	prev[0] = 0;
	string find = "antimatter";
	int S = find.size();
	bool tests[S];
	for (int t=0;t<S;t++) tests[t] = 0;
	for (int i=0; i<n; i = next[i]) {
		tests[0] = 1;
		bool newtests[S];
		for (int t=0;t<S;t++) newtests[t] = 0;
		for (int t=0;t<S;t++) if (tests[t]) {
			if (s[i] == find[t]) {
				if (t<S-1) {
					newtests[t+1] = 1;
				}
				else {
					// back and delete
					int x = i;
					for (int v=0;v<find.size();v++) x = prev[x];
					next[x] = next[i];
					prev[next[i]] = x;
					// back some more
					i = next[i];
					for (int v=0;v<find.size();v++) i = prev[i];
					for (int t=0;t<S;t++) newtests[t] = 0;
				}
			}
		}
		for (int t=0;t<S;t++) tests[t] = newtests[t];
	}
	for (int i=next[0];i<n-1;i = next[i]) {
		cout << s[i];
	}
	cout << endl;
}

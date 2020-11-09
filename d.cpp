
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M,N;
	cin >> M >> N;
	long long data[M][N];
	for (int n=0;n<N;n++) {
		string s; cin >> s;
		for (int m=0;m<M;m++) {
			cin >> data[m][n];
		}
	}
	long long amax = 0, amin = 0;
	for (int m=0;m<M-1;m++) {
		long long mmax = 0, mmin = 0;
		for (int n=0;n<N;n++) {
			long long diff = (data[M-1][n]-data[m][n]) * (5000/data[m][n]);
			mmax = max(mmax,diff);
			mmin = min(mmin,diff);
		}
		amax += mmax;
		amin += mmin;
	}
	cout << "Max: " << amax << endl;
	cout << "Min: " << amin << endl;
}

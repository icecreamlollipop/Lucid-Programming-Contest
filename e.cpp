
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,X;
	cin >> N >> X;
	long double prob[N+1];
	for (int i=0;i<=N;i++) prob[i] = 0;
	prob[0] = 1;
	long double csum = 1;
	for (int d=1;d<N;d++) {
		prob[d] = csum/X;
		csum += prob[d];
		if (d-X>=0) csum -= prob[d-X];
	}
	for (int i=0;i<N;i++) cout << prob[i] << endl;
	long double ev[N+1];
	for (int i=0;i<=N;i++) ev[i] = 0;
	csum = 0;
	for (int d=1;d<N;d++) {
		ev[d] = csum/X;
	}
}

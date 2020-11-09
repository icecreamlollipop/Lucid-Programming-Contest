
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int arr[MAX];
int tree[MAX];
int treesort[MAX];

int make_tree(int index, int level, int cur) {
	if (level<0 || arr[index]==0) return cur;
	cur = make_tree(index*2+1, level-1, cur);
	tree[cur++] = arr[index];
	cur = make_tree(index*2+2, level-1, cur);
	return cur;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i=0;i<n;i++) {
		string s; cin >> s;
		if (s[0] != 'e') {
			sscanf(s.c_str(),"%d",arr+i);
		}
	}
	int nn = n+1;
	int P = 0;
	while (nn>1) {
		P++;
		nn >>= 1;
	}
	int N = make_tree(0, P-1, 0);
	for (int i=0;i<N;i++) treesort[i] = tree[i];
	sort(treesort,treesort+N);
	vector<int> swaps;
	for (int i=0;i<N;i++) {
		if (tree[i] != treesort[i]) swaps.push_back(treesort[i]);
	}
	if (swaps.size()==2) cout << "Swap nodes " << swaps[0] << " and " << swaps[1] << endl;
	else if (swaps.size()==0) cout << endl;
}

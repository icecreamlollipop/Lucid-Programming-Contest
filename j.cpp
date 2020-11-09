
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,E;
	cin >> N >> E;
	int curplanet = 0;
	map<string,int> pinv;
	for (int i=0;i<N;i++) {
		string x;
		cin >> x;
		pinv[x] = curplanet++;
	}
	vector<pair<int,int>> edges[N];
	for (int e=0;e<E;e++) {
		string a,b; int x;
		cin >> a >> b >> x;
		int ai = pinv[a];
		int bi = pinv[b];
		edges[ai].push_back({bi,x});
		edges[bi].push_back({ai,x});
	}
	priority_queue<pair<int,int>> pq;
	bool vis[N];
	for (int i=0;i<N;i++) vis[i] = 0;
	int nvis = 0;
	pq.push({0,0});
	long long ans = 0;
	while (nvis < N) {
		auto p = pq.top();
		pq.pop();
		int vertex = p.second;
		int cost = -p.first;
		if (vis[vertex]) continue;
		vis[vertex] = 1;
		nvis++;
		ans += cost;
		for (auto e : edges[vertex]) pq.push({-e.second,e.first});
	}
	cout << ans << endl;
}

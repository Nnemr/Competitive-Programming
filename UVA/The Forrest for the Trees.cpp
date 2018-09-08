#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(int (i) = (int)a; (i) <=(int)n; ++(i))
#define repa(i,a) for(auto &(i):a)
#define repr(i,a,n) for(int (i) = (int)a; i >=(int)n; --(i))
#define pii pair<int,int>
#define set(x, v) memset(x, v, sizeof(x))
#define vi vector<int>
#define FRead std::ios::sync_with_stdio(false);
#define vii vector<pii>
#define sz(s) s.size()
#define sortAr(x,n) sort(x, x+n)
#define ALL(x) x.begin(), x.end()
#define REV(x) reverse(ALL(x));
#define read(a,n) rep(i,0,n-1) scanf("%d", &a[i]); 
using namespace std;
vi adj[26];
bool vis[26];
void dfs(int i, int res, int &t) {
	if (vis[i])
		return;
	vis[i] = 1;
	rep(a, 0, sz(adj[i]) - 1) {
		if (!vis[adj[i][a]]) {
			t = max(res + 1, t);
			dfs(adj[i][a], res + 1, t);
		}
	}
}
int main() {

	int T;
	cin >> T;
	while (T--) {
		set(vis, 0);
		set(adj, 0);
		string s;
		while (cin >> s && s[0] != '*') {
			adj[s[1] - 'A'].push_back(s[3] - 'A');
			adj[s[3] - 'A'].push_back(s[1] - 'A');
		}
		cin >> s;
		int a, b;
		a = b = 0;
		for (int i = 0; i < sz(s); i += 2) {
			int t = 0;
			if (!vis[s[i] - 'A']) {
				dfs(s[i] - 'A', 0, t);
				if (t == 0)
					++a;
				else
					++b;
			}
		}
		cout << "There are " << b << " tree(s) and " << a << " acorn(s).\n";
	}
}
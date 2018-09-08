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
#define vi vector<ll>
#define FRead std::ios::sync_with_stdio(false);
#define vii vector<pii>
#define sz(s) s.size()
#define sortAr(x,n) sort(x, x+n)
#define ALL(x) x.begin(), x.end()
#define REV(x) reverse(ALL(x));
#define read(a,n) rep(i,0,n-1) cin>>a[i]; 
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		stack<pii> res;
		for (int i = 2 * n; i >= n + 1; --i) {
			if ((n*i) % (i - n) == 0) {
				res.push({ (n*i) / (i - n) ,i});
			}
		}
		cout << sz(res) << endl;
		while (!res.empty()) {
			pii t = res.top();
			res.pop();
			cout << "1/" << n << " = " << "1/" << t.first << " + " << "1/" << t.second << endl;
		}
	}
}
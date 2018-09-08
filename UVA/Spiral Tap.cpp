#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(int (i) = (int)a; (i) <=(int)n; ++(i))
#define repa(i,a) for(auto &(i):a)
#define repr(i,a,n) for(int (i) = (int)a; i >=(int)n; --(i))
#define pii pair<int,int>
#define ep5 (int)1e5
#define set(x, v) memset(x, v, sizeof(x))
#define vi vector<int>
#define FRead std::ios::sync_with_stdio(false);
#define vii vector<pii>
#define sz(s) (int)s.size()
#define sortAr(x,n) sort(x, x+n)
#define ALL(x) x.begin(), x.end()
#define REV(x) reverse(ALL(x));
#define read(a,n) rep(i,0,n-1) scanf("%d", &a[i]); 
using namespace std;
pii dxy[4] = { { 1,0 },{ 0,-1 },{ -1,0 },{ 0,1 } };
pii solve(ll sz, ll p) {
	int step = 1, temp = 1;
	int i, j;
	i = j = (sz / 2) + 1;
	if (sz*sz == p) {
		return{ sz,sz };
	}
	int s2 = 0;
	int ind = 0;
	while (temp<p) {
		if (temp + step <= p) {
			i += (dxy[ind].first *step);
			j += (dxy[ind].second*step);
			temp += step;
		}
		else {
			for (temp; temp < p; ++temp) {
				i += dxy[ind].first;
				j += dxy[ind].second;
			}
			break;
		}
		if (ind&1)
			++step;
		ind = (ind + 1) % 4;
	}
	return{ i,j };
}
int main() {
	ll a, b;
	while (scanf("%lld%lld", &a, &b), a, b) {
		pii res = solve(a, b);
		printf("Line = %d, column = %d.\n", res.first, res.second);
	}
	return 0;
}

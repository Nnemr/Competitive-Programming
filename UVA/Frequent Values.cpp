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
int cnt[(int)2e5 + 1], ar[(int)1e5 + 1];
int st[(int)4e5 + 1], freq[(int)1e5];
void build(int p, int l, int r) {
	if (l == r) {
		st[p] = freq[l];
		return;
	}
	build(p << 1, l, (l + r) / 2);
	build(p << 1 | 1, (l + r) / 2 + 1, r);
	st[p] = max(st[p << 1], st[p << 1 | 1]);
}
int rmq(int p, int l, int r, int ql, int qr) {
	if (l > qr || r < ql)
		return -1;
	if (l >= ql && r <= qr)
		return st[p];
	return max(rmq(p << 1, l, (l + r) / 2, ql, qr),
		rmq(p << 1 | 1, (l + r) / 2 + 1, r, ql, qr));
}
int main() {

	int n, q;
	while (scanf("%d", &n)) {
		if (!n)
			return 0;
		scanf("%d", &q);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &ar[i]);
			++cnt[ar[i] + (int)1e5];
		}
		for (int i = 0; i < n; ++i) {
			freq[i] = cnt[ar[i] + (int)1e5];
		}
		build(1, 0, n - 1);
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (ar[x - 1] == ar[y - 1])
				printf("%d\n", y - x + 1);
			else {
				--x, --y;
				int lc, rc;
				lc = rc = 0;
				while (x > 0 && x <= y && ar[x] == ar[x - 1]) {
					++x;
					++lc;
				}
				while (y >= x && y < n - 1 && ar[y] == ar[y + 1])
					--y, ++rc;
				if (x <= y)
					printf("%d\n", max({ lc,rc, rmq(1, 0,n - 1, x,y) }));
				else
					printf("%d\n", max(lc, rc));
			}
		}
		memset(st, 0, sizeof(st));
		memset(cnt, 0, sizeof(cnt));
		memset(ar, 0, sizeof(ar));
		memset(freq, 0, sizeof(freq));
	}
	return 0;
}
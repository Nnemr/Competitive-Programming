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
int ar[17];
bool used[17];
bool isprime(int n) {
	rep(i, 2, n-1) {
		if (n%i == 0)
			return false;
	}
	return true;
}
void backtrack(int p, int n) {
	if (p == n) {
		if (!isprime(ar[p-1] + 1))
			return;
		rep(i, 1, n) {
			printf("%d", ar[i - 1]);
			if (i != n)
				printf(" ");
			else
				puts("");
		}
		return;
	}
	rep(i, 2, n) {
		if (isprime(i + ar[p - 1])&& !used[i]) {
			ar[p] = i;
			used[i] = 1;
			backtrack(p + 1, n);
			used[i] = 0;
		}
	}
}
int main() {
	FRead;
	int n;
	int i = 0;
	ar[0] = 1;
	used[1] = 1;
	while (scanf("%d", &n) != EOF) {
		if (i++)
			puts("");
		printf("Case %d:\n", i);
		backtrack(1, n);
	}
}
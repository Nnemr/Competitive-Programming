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
int f[11], r[11];
bool vis[100][100][100];
vi values;
void init() {
	set<int>st;
	rep(i, 1, 20) {
		st.insert(i);
		st.insert(i * 2);
		st.insert(i * 3);
	}
	st.insert(50);
	repa(i, st)
		values.push_back(i);
}
int main()
{
	int n;
	init();
	while (scanf("%d", &n) == 1) {
		int c = 0, p = 0;
		if (n <= 0)
			break;
		rep(i, 1, sz(values)) {
			rep(j, 1, sz(values)) {
				rep(k, 1, sz(values)) {
					if (values[i - 1] + values[k - 1] + values[j - 1] == n) {
						++p;
						if (!vis[values[i - 1]][values[j - 1]][values[k - 1]]) {
							++c;
							vis[values[i - 1]][values[j - 1]][values[k - 1]] = 1;
							vis[values[i - 1]][values[k - 1]][values[j - 1]] = 1;
							vis[values[j - 1]][values[i - 1]][values[k - 1]] = 1;
							vis[values[j - 1]][values[k - 1]][values[i - 1]] = 1;
							vis[values[k - 1]][values[j - 1]][values[i - 1]] = 1;
							vis[values[k - 1]][values[i - 1]][values[j - 1]] = 1;
						}
					}
				}
			}
		}
		if (!c && !p) {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, c, n, p);
		}
		puts("**********************************************************************");
	}
	puts("END OF OUTPUT");
}

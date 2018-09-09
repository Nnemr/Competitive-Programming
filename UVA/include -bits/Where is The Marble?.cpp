#include <bits/stdc++.h>
using namespace std;
vector<int>ar;
int search(int n, int q){
	int res = 1e6;
	int lo = 0, hi= n-1;
	while(lo<=hi){
		int mid((lo+hi)>>1);
		if(ar[mid] ==q){
			res = min(mid+1, res);
		}
		if(ar[mid] >= q)
			hi = mid-1;
		else{
			lo = mid+1;
		}
	}
	return res;
}
int main() {
	int n, q;
	int caseCount=0;
	while(scanf("%d%d", &n,&q), n,q){
	printf("CASE# %d:\n", ++caseCount);
	ar.resize(n);
	for(int i = 0 ;i <n;++i){
		scanf("%d", &ar[i]);
	}
	sort(ar.begin(), ar.end());
	
	while(q--){
		int x;
		scanf("%d", &x);
		int res = search(n, x);
		if(res==1e6){
			printf("%d not found\n", x);
		}
		else
			printf("%d found at %d\n", x,res);
	}
	}
}

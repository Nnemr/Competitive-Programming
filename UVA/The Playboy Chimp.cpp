#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int chimps[(int)5e5];
	int ind =0;
	for(int i=0; i<n;++i){
		int x;
		scanf("%d",&x);
		if(ind && chimps[ind-1]==x)
			continue;
		else
			chimps[ind++]=x;
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int x;
		scanf("%d", &x);
		auto low = lower_bound(chimps, chimps+ind, x), hi = upper_bound(chimps,chimps+ind, x);
		--low;
		if(low == ar-1){
			printf("X ");
		}
		else
			printf("%d ", *low);
		if(hi  == ar+ind)
			puts("X");
		else
			printf("%d\n", *hi);
	}
	return 0;
}


#include <cstdio>
using namespace std;
#define maxN 100005
#define m ((L+R)>>1)
int T, N, Q, X, Y, Z, i;
int val[4 * maxN];
void push_down(int o){
	val[o * 2] = val[o * 2 + 1] = val[o];
	val[o] = 0;
}
void update(int o, int L, int R){
	if (X <= L&&R <= Y) val[o] = Z;
	else{
		if (val[o]) push_down(o);
		if (X <= m) update(o * 2, L, m);
		if (Y > m) update(o * 2 + 1, m + 1, R);
	}
}
int sum(int o,int L,int R){
	if (val[o]) return (R-L+1)*val[o];
	return sum(o * 2, L, m) + sum(o * 2 + 1, m + 1, R);
}
int main(){
	scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++){
		val[1] = 1;
		scanf("%d%d", &N, &Q);
		for (i = 0; i < Q; i++){
			scanf("%d%d%d", &X, &Y, &Z);
			update(1, 1, N);
		}
		printf("Case %d: The total value of the hook is %d.\n",Case,sum(1,1,N));
	}
	return 0;
}

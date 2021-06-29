#include <stdio.h>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define STRS(i,str) for(int i = 0; (str)[i]; i++)
#define CHINO(a,n) int n, *a; scanf("%d", &n); a = (int *)malloc(sizeof(int) * n); for(int i = 0; i < n; i++) scanf("%d", a + i)

int put(int *a, int n){
	REP(i, n - 1) printf("%d ", a[i]);
	printf("%d\n", a[n - 1]);
}

int main(){
	int a[120];
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", a + i);
	REP(i, n){
		int tmp = a[i];
		RREP(j, i){
			if(a[j] > tmp){
				a[j+1] = a[j];
				a[j] = tmp;
			}else break;
		}
		put(a, n);
	}
}

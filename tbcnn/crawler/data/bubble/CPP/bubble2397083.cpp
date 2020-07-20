#include <stdio.h>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define STRS(i,str) for(int i = 0; (str)[i]; i++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAXI(a,b) if(a < (b)) a = (b)
#define MINI(a,b) if(a > (b)) a = (b)

int main(){
	int n;
	int a[120];
	int count = 0;
	scanf("%d", &n);
	REP(i, n) scanf("%d", a + i);
	bool flag = 1;
	while(flag){
		flag = 0;
		RFOR(i, n, 1)
			if(a[i] < a[i - 1]){
				int tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
				count++;
				flag = 1;
			}
	}
	REP(i, n - 1) printf("%d ", a[i]);
	printf("%d\n%d\n", a[n - 1], count);
}

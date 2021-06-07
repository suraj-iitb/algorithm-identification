#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// AIZUonline BinarySearch
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=jp
// ***********************
#define PRINCR do{printf("\n");fflush(stdout);}while(0)
#define GETLINE(str) do{char *p;fgets(str,sizeof(str),stdin);p=strchr(str,'\n');if(p)*p='\0';}while(0)
#define REP(a,b) for(int a=0;a<(int)(b);++a)
static char *GETWORD(char* str) {char c;char *cp;cp=&str[0];c=fgetc(stdin);while( c != EOF ){if((c==' ')||( c=='\n')) break;*cp++=c;c=fgetc(stdin);}*cp='\0';return &str[0];}
#define	GETINTS(a,b) {char s[34];int *ap=a;REP(i,b){GETWORD(s);sscanf(s,"%d", ap);ap++;}}
static int GETLINEINT(void) {char s[34];GETLINE(s);return atoi(s);}
static int GETWORDINT(void) {char s[34];GETWORD(s);return atoi(s);}
static long GETWORDLONG(void) {char s[34];GETWORD(s);return atol(s);}
#define SWAP(type,a,b) do{type _c;_c=a;a=b;b=_c;}while(0)
int BinarySearch(int vec[] , int max, int key) {
	// key: 検索対象の値
	int	 	left = 0;
	int		right = max;
	int		mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (vec[mid] == key) {
			return	mid;
		} else if (key < vec[mid]) {
			// 半分より下
			right = mid;
		} else {
			// 半分より上
			left = mid + 1;
		}
	}
	// key が配列の中に見つからない場合
	return -1;
}
int main( void ) {
	int maxidx;
	int	query;
	int	val;
	int	*DIC, *dp;
	int	cnt = 0;

	maxidx = GETLINEINT();
	DIC = (int*)malloc( maxidx * sizeof(int) );
	if( DIC == NULL ) return 12;
	dp = DIC;
	
	REP(i,maxidx) {
		*dp++ = GETWORDINT();
	}
	query = GETLINEINT();
	REP(i,query) {
		val = GETWORDINT();
		if( BinarySearch( DIC , maxidx, val ) >= 0 ) {
			cnt++;
		}
	}
	printf("%d\n", cnt );
	free(DIC);
}


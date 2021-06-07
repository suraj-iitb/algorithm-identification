#include <stdio.h>
#define N 10000

int n, A[N];
int linearSearch(int key){
    int i = 0;
    A[n] = key;
    while( A[i]!=key){
    i++;
    if(i>=n) return 0;
    }
    return 1;
}

int main(void){
    int q, key, c=0, j;
    scanf("%d", &n);
	for(j=0; j<n; j++) scanf("%d", &A[j]);
	
	scanf("%d", &q);
	for(j=0; j<q; j++){
	    scanf("%d", &key);
	    if(linearSearch(key)) c++;
	}
	printf("%d\n", c);
	return 0;
}

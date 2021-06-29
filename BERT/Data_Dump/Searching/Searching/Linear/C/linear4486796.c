#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int n,*S;
	int q,*T;
	int count=0;

	scanf("%d",&n);
	S=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	T=(int*)malloc(sizeof(int)*q);
	for(int i=0;i<q;i++){
		scanf("%d",&T[i]);
	}

	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			if(T[i]==S[j]){
				count++;
				break;
			}
		}
	}
	printf("%d\n",count);

   return 0;
}

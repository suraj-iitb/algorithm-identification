#include <stdio.h>
int count=0;
void liner_serch(int S[],int T[],int n,int q);
int main(void){
	int i,n;
	scanf("%d",&n);
	int S[n];
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	int q;
	scanf("%d",&q);
	int T[q];
	for(i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	
	liner_serch(S,T,n,q);
	printf("%d\n",count);
}


void liner_serch(int S[],int T[],int n,int q){
	int i,j;
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			if(T[i]==S[j]){
				count++;
				break;
			}
		}
	}
}

#include<stdio.h>
int main(void){
	
	int n,q;
    scanf("%d",&n);
    
    int S[n];
    int t;
	int count=0;
	int i,j;


	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&t);
		for(j=0;j<n;j++){
			if(t==S[j]){
				count++;
				break;
			}
		}
	}
    printf("%d\n",count);
}

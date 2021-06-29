#include<stdio.h>


int search(int S[], int n, int T);

int main(void){
int i,n,S[10000+1],q,T,sum = 0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&T);
		if(search(S,n,T)){
			sum++;
		}
	}
	printf("%d\n",sum);
	
	return 0;
}

int search(int S[], int n, int T){
	int i = 0;
	S[n] = T;
	while (S[i] != T )
	{
		i++;
	}
	return i != n;
}




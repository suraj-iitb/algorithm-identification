#include<stdio.h>

int linearSearch(int s[],int key,int n){
   
	int i = 0;
   s[n] = key;
	while (s[i] != key) {
		i++;
		if(i==n){// i が n に達した
			return n;
		}
	}
   return i;
}

int main(void){

	int n;
	
	scanf("%d",&n);
	
	int S[n+1];
	int i;
	
	for(i=0;i<n;i++){
	
		scanf("%d",&S[i]);
	
	}
	
	int q;
	scanf("%d",&q);
	
	int T[q];
	
	for(i=0;i<q;i++){
	
		scanf("%d",&T[i]);
	
	}
	
	int Sum=0;
	
	for(int j=0;j<q;j++){
		if(linearSearch(S,T[j],n)!=n){
			Sum++;
		}
	}
	
	printf("%d\n",Sum);
	
}


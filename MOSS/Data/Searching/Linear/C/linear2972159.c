#include <stdio.h>
#define N 10000
#define NOT_FOUND -1
int n,q;
int linearSearch(int[],int);

int main(){
    int i,cnt=0,S[N],T[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
      scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }

    for(i=0;i<q;i++){
		if(linearSearch(S,T[i])!=NOT_FOUND){
			cnt++;
		}
	}
    
	printf("%d\n",cnt);


    return 0;
}

int linearSearch(int A[N],int x){
         int i = 0;
		 A[n]  = x;
		 while(A[i]!=x){
			 i++;
		 }
		   if(i == n){
				  return NOT_FOUND;
		 	}
	return i;
		
}

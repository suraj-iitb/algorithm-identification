#include <stdio.h>
#define N 10000000
#define NOT_FOUND -1
int S[N],T[N],n,q;
int linearSearch(int[],int);

int main(){
    int i,cnt=0;
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
         int i = 0,left,right,mid=0;
		 left = 0;
         right = n;
        
		 while(left < right){
			 mid = (left + right) / 2;
                if(A[mid] == x){
                    return mid;
                    }
                    else if(x < A[mid]){
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
		 }
	return NOT_FOUND;;
		
}


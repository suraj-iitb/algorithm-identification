#include <stdio.h>

int S[1000000],n;

int binarySearch(int T){
	int left = 0;
	int right = n;
	int mid;
	while (left < right){
		mid = (left + right) / 2;
		if (S[mid] == T){
			return 1;
		}
		
		if(T<S[mid]){
            right = mid;
		}else if(T>S[mid]){
            left = mid + 1;
		}
	}
    return 0;
}

int main(void){
	int q,i,T;
	int count=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(i=0;i<q;i++){
		scanf("%d",&T);
		count+=binarySearch(T);
	}
	printf("%d\n",count);
	return 0;
}

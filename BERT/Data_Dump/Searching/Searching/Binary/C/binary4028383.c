#include<stdio.h>

int binarySearch(int A[],int key, int n){
    int left = 0;
    int right = n;
	int mid;
	while (left < right){
        mid = (left + right) / 2;
		if (A[mid] == key){
            return mid;
		}
	
		else if (key < A[mid]){
            right = mid;
		}
		else{
            left = mid + 1;
		}
	}
	
    return n;
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
		if(binarySearch(S,T[j],n)!=n){
			Sum++;
		}
	}
	
	printf("%d\n",Sum);
	
}


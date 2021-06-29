#include <stdio.h>
#define N 100000

int n, A[N];
binarySearch(int key){
    int left = 0;
    int right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if (A[mid] == key) return mid;
        else if(key < A[mid]) right = mid;
        else left = mid + 1;
    }
    return 0;
}

int main(void){
    int q, key, i, c=0;
    scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &A[i]);
	
	scanf("%d", &q);
	for(i=0; i<q; i++){
		scanf("%d", &key);
		if(binarySearch(key)!=0) c++;
	}
    printf("%d\n", c);
	
	return 0;
}

#include<stdio.h>

int binarysearch(int a[], int n, int key)
{
	int left = 0;
	int right = n;
	
	while(left < right){
		int mid = (left + right) / 2;
		
		if(a[mid] == key){
			return 1;
		}else if(key < a[mid]){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	
	return 0;
}

int main()
{
	int n, q, i;
	int count = 0;
	int a[100000];
	int t[50000];
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &q);
	
	for(i = 0; i < q; i++){
		scanf("%d", &t[i]);
		
		if(binarysearch(a, n, t[i]) == 1){
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}

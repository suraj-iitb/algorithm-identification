#include <stdio.h>
int array[100000],n;
int main() {
	int i,j,k,sum = 0;
	scanf("%d",&n);
	for(i = 0; i < n ;i++) {
		scanf("%d",&array[i]);
	}
	scanf("%d",&j);
	for(i = 0; i < j; i++) {
		scanf("%d",&k);
		if(BinarySearch(k))
		 sum++;
	}
	printf("%d\n",sum);
	return 0;

}


int BinarySearch(int key) {
	int left = 0;
	int right = n;
	int center;
	while(left < right) {
		center  = (left + right) / 2;
		if(key == array[center]) 
			return 1;
		if(key > array[center]) 
			left = center + 1;
		else if (key < array[center])
			right = center;
	}
	return 0;
}



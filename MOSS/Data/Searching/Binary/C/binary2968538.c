#include<stdio.h>
#include<stdlib.h>

int T[50000],S[100000];
	int binarySearch(int,int);
int main() {
	int n,i,q,j,k=0;
	scanf("%d",&n);
	for(j=0;j<n;j++) {
		scanf("%d",&S[j]);
	}
	
	scanf("%d",&q);
	for(i=0;i<q;i++) {
		scanf("%d",&T[i]);
		if(binarySearch(T[i],n)==1) k++;
	}
printf("%d\n",k);
return 0;
}
	
	int binarySearch(int key, int n) {
 int   left = 0,mid;
     int right = n;
    while( left < right) {
        mid = (left + right) / 2;
        if (S[mid] == key)
            return 1; 
        else if (key < S[mid])
            right = 	mid;
        else
            left = mid + 1;
          }
      return 0;
    
    }

#include <stdio.h>

int binarysearch(int right, int s[], int key){
    int left = 0;
    int mid;
	while(left<right){
        mid = (left + right) / 2;
        if(s[mid] == key){
            return 1;
        }else if( key < s[mid]){
            right = mid;
        }else{
            left = mid + 1;
    	}
    }
	return 0;
}

int main(void){
    int rt, lt = 0;
    int key, mid;
    int n, q, count=0;
    int i,j;
	int t[100001];
	int s[100001];
	scanf("%d", &n);
    for (i=0; i<n; i++){
    	scanf("%d", &s[i]);
    }
	scanf("%d", &q);
    for (i=0; i<q; i++){
    	scanf("%d", &t[i]);
    }
    for(i=0; i<q;i++){
    	if (binarysearch(n, s, t[i])){
    		count++;
    	}
    }
	printf("%d\n", count);
    return 0;
}

#include<stdio.h>

int n;
int S[100000];

int binarySearch(int key);


int main(void){
	int q;
	int i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){			//S入力
		scanf("%d",&S[i]);
		}
	scanf("%d",&q);
	int k;
	for(i=0;i<q;i++){			//T入力
		scanf("%d",&k);
		if(binarySearch(k)){
			count++;
			}
	}
	printf("%d\n",count);
	return 0;
}


int binarySearch(int key){
	int left = 0;
    int right = n;
    while (left < right){
       int mid = (left + right) / 2;
        if (S[mid] == key){
            return 1;
            }
        if(key>S[mid]){
            left = mid + 1;
            }
        else if(key<S[mid]) {
            right = mid;
            }
    }
	 return 0;
}
		

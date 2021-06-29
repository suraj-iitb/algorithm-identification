//16D8104007J Kanehiro Maho
#include<stdio.h>
int main(void){
	
	int n,q;
    scanf("%d",&n);
    int mid, left, right;
    int S[n];
    int t;
	int count=0;
	int i,j;

	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
		
	for(i=0; i<q; i++){
		scanf("%d",&t);
		left = 0;
		right = n;
		while(left < right){
			mid = (left+right)/2;
			if(t == S[mid]){
				count++;
				break;
			}
			if(t > S[mid]){
				left = mid+1;
			}else if(t < S[mid]){
				right = mid;
			}
		}
	}

    printf("%d\n",count);

}


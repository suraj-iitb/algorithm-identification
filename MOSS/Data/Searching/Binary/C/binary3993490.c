#include<stdio.h>
#include<math.h>

int main(){

	int n;
	scanf("%d",&n);
	int S[100000];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);	
	}
	
	int q;
	scanf("%d",&q);
	int T[50000];
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);	
	}
	
	int C=0;
	int key=0;
	int k;
	for(i=0;i<q;i++){
		key=T[i];
		int left=0;
		int right=n-1;
		for(k=0;(double)k<log2((double)n);k++){
			int middle=(right+left)/2;
			if(key==S[middle]){
			C++;
			break;
			}
			else if(key<S[middle]){
				right=middle;
			}
			else if(key>S[middle]){
				left=middle+1;
			}
		}
	}
	
	
	printf("%d\n",C);
	return 0;
}

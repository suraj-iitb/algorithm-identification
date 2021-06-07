#include <stdio.h>

int main(void){
	int n,q;
	int s[100000],t[50000];
	int i,c=0;
	int left,right,center;

	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&s[i]);
	}

	scanf("%d",&q);
	for(i=0;i<q;++i){
		scanf("%d",&t[i]);
	}
	
	for(i=0;i<q;++i){
		left = 0;
		right = n;
		while(left<right){
			center = (left+right)/2;
			if(s[center]==t[i]){
				c++;
				break;
			}else if(s[center]>t[i]){
				right = center;
			}else{
				left = center+1;				
			}
		}
	
	}
	printf("%d\n",c);
	
	return 0;
}

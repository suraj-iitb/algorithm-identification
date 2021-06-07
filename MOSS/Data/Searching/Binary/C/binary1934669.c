#include<stdio.h>
int main(void){
	int n,q,i,j,c=0,left,right,mid=0;
	int s[100000],t[50000];
	scanf("%d",&n);
	for(i=0; i<n  ; i=i+1 ){
		scanf("%d", &s[i] );
	}
	scanf("%d",&q);
	for(i=0;i<q ; i=i+1){
		scanf("%d",&t[i]);
	}//??¢?´¢
	for(i=0;i<q;i=i+1){
		left=0,right=n;
		while(left<right){
			mid=(left+right)/2;
			if(s[mid]==t[i]){
				c=c+1;
				break;
			}
			else if(t[i]<s[mid]){
				right=mid;
			}
			else{
			left=mid+1;
			}
		}
	}
	
	
	
	
	printf("%d\n",c);
	return 0;
}

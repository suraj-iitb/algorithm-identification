#include<stdio.h>

int main(){
	int n,s[100000],q,t,c=0,i;
	int left,mid,right;

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&s[i]);

	scanf("%d",&q);

	for(i=0;i<q;i++){
		scanf("%d",&t);

		//seach
		left=0;
		right=n;
		while(left<right){
			mid=(left+right)/2;
			if(s[mid]==t){
				c++;
				break;
			}
			else if(t<s[mid])
				right=mid;
			else
				left=mid+1;
		}


	}
	printf("%d\n",c);

	return 0;
}

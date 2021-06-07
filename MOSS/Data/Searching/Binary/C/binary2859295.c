#include<stdio.h>
int main(void)
{
	int n,q;
	int s[100000]={0},t[50000]={0};
	int i;
	int cnt=0;
	int min,max,mid,tar;
	
	//min=0;
	//max=n-1;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&t[i]);
	}
	
	for(i=0;i<q;i++){
		tar=t[i];
		min=0;
		max=n-1;
		while(min<=max){
			mid=(min+max)/2;
			if(s[mid]==t[i]){
				cnt++;
				break;
			}else if(s[mid]<t[i]){
				min=mid+1;
			}else if(s[mid]>t[i]){
				max=mid-1;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

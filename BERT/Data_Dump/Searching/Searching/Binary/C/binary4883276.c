#include<stdio.h>

int main(void)
{
	int n,q,i,count=0,mid,min,max;
	
	scanf("%d",&n);
	
	int s[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	
	int t[q];
	
	for(i=0;i<q;i++){
		scanf("%d",&t[i]);
	}
	
	for(i=0;i<q;i++){
		min=0;
		max=n;
		
		for(;;){
			mid=(max + min)/2;
			
			if(t[i] == s[mid]){ 
				count++;
				break;
			}else if(min >= max){
				break;
			}else if(t[i]<s[mid]){
				max = mid;
			}else{
				min = mid + 1;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}

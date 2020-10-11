#include <stdio.h>

int main(){
	int n,i,j,count=0,min,num[1000],temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(num[j]<num[min])
			{
				min=j;
			}
		}
		temp=num[i];
		num[i]=num[min];
		num[min]=temp;
		if(i!=min) count++;

	}
	for(i=0;i<n;i++){
	printf("%d",num[i]);
	if(i!=n-1) printf(" ");
}
printf("\n");
printf("%d\n",count);
return 0;
}

#include <stdio.h>

int main(){
int n,i,count=0,j,temp,num[1000];
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&num[i]);
}
for(i=0;i<n-1;i++)
{
	for(j=n-1;j>i;j--){
		if(num[j-1]>num[j]){
			temp=num[j-1];
			num[j-1]=num[j];
			num[j]=temp;
			count++;
		}
	}
}
for(i=0;i<n;i++)
{
	printf("%d",num[i]);
	if(i!=n-1) printf(" ");
}
printf("\n");
printf("%d\n",count);
return 0;
}

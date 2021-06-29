#include<stdio.h>

int main(void)
{
int n,i,j,k,v;
scanf("%d\n",&n);
int array[n];
for(i=0;i<n;i++) scanf("%d ",&array[i]);
for(i=0;i<n;i++)
{
v=array[i];
j=i-1;
while(j>=0 && array[j]>v)
{
array[j+1]=array[j];
j--;
}
array[j+1]=v;
for(k=0;k<n-1;k++) printf("%d ",array[k]);
printf("%d\n",array[n-1]);}
return 0;
}

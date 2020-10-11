#include<stdio.h>
 
int main(void)
{
int N,i,n,j,a;
n=0;
scanf("%d\n",&N);
int array[N];
for(i=0;i<N;i++) scanf("%d ",&array[i]);
for(i=0;i<N;i++)
{
for(j=N-1;j>i;j--)
{
if(array[j]<array[j-1]){
a=array[j-1];
array[j-1]=array[j];
array[j]=a;
n++;
}
}
}
for(i=0;i<N-1;i++) printf("%d ",array[i]);
printf("%d\n%d\n",array[N-1],n);
return 0;
}

#include<stdio.h>

int main(void)
{
int N,i,mini,j,swap=0,a;
scanf("%d\n",&N);
int array[N];
for(i=0;i<N;i++) scanf("%d ",&array[i]);
for(i=0;i<N-1;i++)
{
mini=i;
for(j=i+1;j<N;j++)
{
if(array[j]<array[mini]) mini=j;
}
if(mini!=i){
swap++;
a=array[i];
array[i]=array[mini];
array[mini]=a;
}
}
for(i=0;i<N-1;i++) printf("%d ",array[i]);
printf("%d\n%d\n",array[N-1],swap);
return 0;
}

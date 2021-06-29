#include<stdio.h>
int search(int A[],int i,int j){
int k=0;
A[i]=j;
while(A[k]!=j)
k++;
return k!=i;
}

int main(void){
int i,j,k,l,A[100001],sum;
scanf("%d",&i);
for(k=0;k<i;k++)
scanf("%d",&A[k]);
scanf("%d",&l);
for(k=0;k<l;k++){
scanf("%d",&j);
if(search(A,i,j))
sum++;
}
printf("%d\n",sum);

return 0;
}

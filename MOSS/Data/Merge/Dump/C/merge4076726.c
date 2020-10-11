#include<stdio.h>
#define N 500000
int temp[N],cnt=0;
int main();
void mergesort(int A[],int left,int right)
{
int mid,i,j,k;
if(left<right){

mid=(left+right)/2;

mergesort(A,left,mid);
mergesort(A,mid+1,right);

for(i=mid;i>=left;i--){temp[i]=A[i];}
for(j=mid+1;j<=right;j++){
  temp[right-(j-(mid+1))]=A[j];
}
i=left;
j=right;
for(k=left;k<=right;k++){
if(temp[i]<temp[j])
A[k]=temp[i++];
else A[k]=temp[j--];
cnt++;
}
}
}
int main()
{
int i,kazu,A[N];

scanf("%d",&kazu);
for(i=0;i<kazu;i++){
scanf("%d",&A[i]);
}
mergesort(A,0,kazu-1);
for(i=0;i<kazu;i++)
{
  if(i>0)printf(" ");
  printf("%d",A[i]);
}
printf("\n");
printf("%d\n",cnt);
return 0;
}


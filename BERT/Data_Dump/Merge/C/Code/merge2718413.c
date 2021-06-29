#include<stdio.h>
#define MAX 500001 /*500000*/
#define INF 10000000

void merge(int A[],int left,int mid,int right,int *cnt){
int i,j,n1,n2;
int L[MAX];
int R[MAX];
int k;
n1=mid-left;
n2=right-mid;

for(i=0;i<n1;i++)L[i]=A[left+i];
for(i=0;i<n2;i++)R[i]=A[mid+i];

L[n1]=2147483647;
R[n2]=2147483647;

i=0;
j=0;

for(k=left;k<right;k++){
  if(L[i]<=R[j]){(*cnt)++;
    A[k]=L[i];
    i++;
  }
  else{(*cnt)++;
    A[k]=R[j];
    j++;
  }
}


return;
}



void mergesort(int A[],int left,int right,int *cnt){
int mid;
 if(left+1 < right){
   mid=(left+right)/2;
   mergesort(A,left,mid,cnt);
   mergesort(A,mid,right,cnt);
   merge(A,left,mid,right,cnt);
 }

return;
}



int main(){
int n,i;
int A[MAX];
int cnt=0;

scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&A[i]);

mergesort(A,0,n,&cnt);

for(i=0;i<n-1;i++)printf("%d ",A[i]);
printf("%d\n",A[n-1]);

printf("%d\n",cnt);

return 0;
}

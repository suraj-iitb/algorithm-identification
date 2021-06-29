#include<stdio.h>
#define N 500000
void merge(int A[],int left,int right);
int count=0;

int main(){ 
    int i,n,S[N];
scanf("%d",&n);    
for(i=0;i<n;i++) scanf("%d",&S[i]);
merge(S,0,n-1);

for(i=0;i<n-1;i++)
printf("%d ",S[i]);
printf("%d",S[n-1]);
printf("\n%d\n",count);

return 0;
}

void merge(int A[],int left,int right){
int i,j,k,L[N],mid;
  //n1 = mid - left;
  //n2 = right - mid;
//  L[0...n1], R[0...n2] を生成
if(left<right){
    mid=(left+right)/2;
    merge(A, left, mid); 
    merge(A, mid+1, right); 
  for(i=mid;i>=left;i--){
    L[i] = A[i];
    count++;
  }
  for(j=mid+1;j<=right;j++){
    L[right-(j-(mid+1))] = A[j];
    count++;
  }
i=left;
j=right;
for(k=left;k<=right;k++){
    if(L[i]<L[j]) {
      A[k]=L[i++]; 
    }
    else {
      A[k]=L[j--]; 
    }
}
}
}

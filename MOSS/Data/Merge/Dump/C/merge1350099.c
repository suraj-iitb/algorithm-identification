#include<stdio.h>

int count=0;
void margesort(int *,int,int);
void marge(int *,int,int,int);

int S[5000000],L[2500001],R[2500001];

int main(){
  int n,i;
  scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d",&S[i]);

   margesort(S,0,n);

   for(i=0;i<n-1;i++) printf("%d ",S[i]);
   printf("%d\n",S[i]);
   
   printf("%d\n",count); 
   
   return 0;
}

void margesort(int *S,int left,int right){
  int mid;
  if(left+1 < right){ 
    mid = (left + right)/2;
    margesort(S,left,mid);
    margesort(S,mid,right);
    marge(S,left,mid,right);
  }
}

void marge(int *S,int left,int mid,int right){
  int n1,n2;
  int i,j=0,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++) L[i] = S[left+i];
  L[n1]=1000000001;
  for(i=0;i<n2;i++) R[i] = S[mid+i];
  R[n2]=1000000001;

  i=0;
  for(k=left;k<right;k++){
  if(L[i] <= R[j]){  
    S[k] = L[i];
    i++;
  }
  else{
    S[k] = R[j];
    j++;
  }
  count++;
  }
}

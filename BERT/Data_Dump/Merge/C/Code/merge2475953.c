#include <stdio.h>
#define sentinel 1000000000
#define N 500000

int count=0;

void Merge(int a[],int left,int mid,int right){
  int n1,n2,i,j,L[N],R[N],k;
  n1= mid-left;
  n2 = right - mid;
  for(i=0;i<n1;i++){
    L[i] = a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
  }

  L[n1]=sentinel;
  R[n2]=sentinel;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<R[j]){
      a[k]=L[i];
      i++;
      count++;
    }else{
      a[k] = R[j];
      j++;
      count++;
    }
  }
}



void Merge_sort(int a[],int left,int right){
  int mid;
  if(left+1<right){
  mid = (left + right )/2;
  Merge_sort(a,left,mid);
  Merge_sort(a,mid,right);
  Merge(a,left,mid,right);
}

}



int main(){
  int n,i,a[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  Merge_sort(a,0,i);
  for(i = 0; i < n-1  ; i++) {
   printf("%d ",a[i]);
 }

 printf("%d\n",a[n-1]);
 printf("%d\n",count);
 return 0;


}

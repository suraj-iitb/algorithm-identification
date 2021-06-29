#include <stdio.h>
void merge(int,int,int);
void sort(int,int);
int m[500000];
int a = 0;
main()
{
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
   {
    scanf("%d",&m[i]);
   }
  sort(0,n);
  for(i=0;i<n;i++)
   {
    printf("%d",m[i]);
    if(i < n-1)
      printf(" ");
   }
  printf("\n");
  printf("%d\n",a);
  return 0;
}
 
void merge(int left,int mid,int right)
  {
  int i,j,k, g = mid - left,h = right - mid;
  int L[g],R[h];
  for(i=0;i<g;i++){
    L[i]=m[left + i];
  }
 
  for(i=0;i<h;i++){
    R[i]=m[mid + i];
  }
  L[g] = 1000000000;
  R[h] = 1000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      m[k] = L[i];
      i++;
    }
    else{
      m[k]=R[j];
      j+=1;
    }
    a+=1;
  }
}
 
void sort(int left,int right){
  int mid;
  if (left+1 <right){
    mid = (left + right) / 2;
    sort(left, mid);
    sort(mid, right);
    merge(left, mid, right);
  }
}

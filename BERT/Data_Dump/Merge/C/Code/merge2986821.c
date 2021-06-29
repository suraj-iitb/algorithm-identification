#include<stdio.h>
#include<limits.h>
#define MAX 500000
int s[MAX],count=0;
void merge(int, int,int);
void mergeSort(int,int);
int main(){
  int n,mid,left,right,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  mergeSort(0,n);
  for(i=0;i<n;i++){
    if(i!=n-1){
    printf("%d ",s[i]);
    }
    else printf("%d\n%d\n",s[i],count);
  }
}


void merge(int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int l[n1+1],r[n2+1];
  int i,j,k;
    for(i=0;i<n1;i++){
    l[i]=s[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=s[mid+i];
  }
   l[n1]=INT_MAX;
   r[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      count++;
      s[k]=l[i];
      i=i+1;
    }
    else{
      count++;

      s[k]=r[j];
      j=j+1;
    }
  }
  

}
void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }


}



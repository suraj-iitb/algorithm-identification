#include<stdio.h>
#define INFINITY 2000000000
int c=0,l[250000+1],r[250000+1];

void merge(int a[],int n,int left,int mid,int right){
  int i,j,k,n1,n2;
  n1=mid-left;n2=right-mid;
  for(i=0;i<n1;i++)l[i]=a[left+i];
  for(i=0;i<n2;i++)r[i]=a[mid+i];
  l[n1]=INFINITY;
  r[n2]=INFINITY;
  i=0;j=0;
  for(k=left;k<right;k++){
    c++;
    if(l[i]<=r[j]){
      a[k]=l[i];
      i++;
    }
    else{a[k]=r[j];j++;}
  }
}
void mergesort(int a[],int n,int left,int right){
  int mid;
  if(left+1<right){
      mid=(left+right)/2;
      mergesort(a,n,left,mid); 
      mergesort(a,n,mid,right); 
      merge(a,n,left,mid,right); 
    }
}


int main(){
  int i,n,s[500000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  mergesort(s,n,0,n);

  for(i=0;i<n-1;i++) printf("%d ",s[i]);
  printf("%d\n%d\n",s[n-1],c);
  return 0;
}


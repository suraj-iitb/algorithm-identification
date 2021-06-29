#include<stdio.h>
#define N 500000
#define SENTINEL 1000000000

void Merge(int[],int,int,int);
void MergeSort(int[],int,int);
int s[N];
int count=0;

int main(){
  
  int i,n=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){ 
    scanf("%d",&s[i]);    
  }

  MergeSort(s,0,n);


  for(i=0;i<n;i++){
    printf("%d",s[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  
  printf("\n%d\n",count);

  return 0;
}

void Merge(int s[],int left,int mid,int right){
  
  int n1=0,n2=0,i,j=0,k=0;
  n1=mid-left;
  n2=right-mid;
  int l[n1+1];
  int r[n2+1];
  
  for(i=0;i<n1;i++){
    l[i]=s[left+i];
  }
  
  for(i=0;i<n2;i++){
    r[i]=s[mid+i];
  }
  l[n1]=SENTINEL+1;
  r[n2]=SENTINEL+1;
  i=0;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      s[k]=l[i];
      i+=1;
      count++;
    } else{
      s[k]=r[j];
      j+=1;
      count++;
    }
  }  
  
}

void MergeSort(int s[],int left,int right){
  
  int mid=0;
  if(left+1 < right){
    
    mid=(left+right)/2;
    MergeSort(s,left,mid);
    MergeSort(s,mid,right);
    Merge(s,left,mid,right);
    
  }

  
}

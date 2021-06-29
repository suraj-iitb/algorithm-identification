#include<stdio.h>

void merge(int,int,int);
void mergeSort(int,int);

int count=0,S[500000];
int main(){
  int i,n,left=0,mid,right;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  right=n;
  mergeSort(left,right);
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1)printf(" ");
    if(i==n-1)printf("\n");
  }
  printf("%d\n",count);
}



void merge(int left,int mid,int right){
    int i,j,k,n1,n2,L[mid-left],R[right-mid];
    n1=mid-left;
    n2=right-mid;
    for(i=0;i<n1;i++){
      L[i]=S[left+i];
    }
    L[n1]=1000000001;
    for(j=0;j<n2;j++){
      R[j]=S[mid+j];
    }
    R[n2]=1000000001;
    i=0;
    j=0;
    for(k=left;k<right;k++){
      if(L[i]<=R[j]){
	S[k]=L[i];
	i=i+1;
	count++;
      } else {
	S[k]=R[j];
	j=j+1;
	count++;
      }
    }
  }

void mergeSort(int left,int right){
    int mid;
    if((left+1)<right){
      mid=(left+right)/2;
      mergeSort(left,mid);
      mergeSort(mid,right);
      merge(left,mid,right);
    }
  }
    
	
    
    
      
  
  
  


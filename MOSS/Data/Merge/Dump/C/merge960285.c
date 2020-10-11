#include <stdio.h>
#define N 1000000
 
int A[N];
int c=0;


void Merge(int [],int,int,int);

void Merge_Sort(int [],int,int);


int main(){
    int n,i;
     
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    Merge_Sort(A,0,n);

     
   for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",c);
    return 0;
     
}


void Merge(int A[],int left,int mid,int right){
    int n1,n2;
    int i=0,j=0,k;
    int L[N],R[N];
     
    n1=mid-left;
    n2=right-mid;
     
    for(i=0;i<n1;i++){
      L[i]=A[left+i];
    }
    for(j=0;j<n2;j++){
      R[j]=A[mid+j];
    }
    
    i=0;
    j=0;
    
    L[n1] = 2147483647;
    R[n2] = 2147483647;
    for(k=left;k<right;k++){
      if(L[i]<=R[j]){
	A[k]=L[i];
	c++;
	i++;
      }else{
	A[k]=R[j];
	c++;
	j++;
      }
    }
    
}



void Merge_Sort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    Merge_Sort(A,left,mid);
    Merge_Sort(A,mid,right);
    Merge(A,left,mid,right);
  }
}

#include <stdio.h>


#define N 600000
#define SENT 1000000001
int L[N],R[N],A[N];
void Merge (int*,int,int,int);
void Msort (int*,int,int);                                 
int a=0,b=0,cout=0;

int main(){
 
  scanf("%d",&a);
  
  for(int i=0;i<a;i++){
     scanf("%d",&A[i]);
  }
  

  Msort(A,0,a);
  
  for(int i=0;i<a;i++){
     printf("%d",A[i]);
     if(i<a-1)printf(" ");
  }
  printf("\n%d\n",cout);
   
return 0;
}

void Merge(int *A ,int left,int mid,int right){
    int i=0,j=0,k=0;
    int m1=mid-left;
    int m2=right-mid;
    
    for(int i=0;i<m1;i++){
       L[i] = A[left+i];
    }
    
    for(int i=0;i<m2;i++){
       R[i] = A[mid+i];
    }
    L[m1] =  SENT;
    R[m2] =  SENT;

    for(int i=left;i<right;i++){
    cout++;
        if(L[j]<=R[k]){
            A[i] =L[j];
            j++;
        }
        else{
          A[i] = R[k];
          k++;
        }
        
    }
}

void Msort(int *A ,int left,int right){
    
    
    if(left+1<right){
    int mid=(left+right)/2;
    Msort(A,left,mid);
    Msort(A,mid,right);
    Merge(A,left,mid,right);
    }

}

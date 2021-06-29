#include<stdio.h>
#include<stdlib.h>
#define VMAX 999999999
typedef struct{
  int n;
  char c;
}member;
void quickSort(member *,int,int);
int partition(member *,int,int);
void swap(member *,member *);
void merge(member *,int,int,int);
void mergeSort(member *,int,int);
int main(){
  int i,n,flag=0;
  member *A,*B;
  scanf("%d",&n);
  A = (member *)malloc(n * sizeof(member));
  B = (member *)malloc(n * sizeof(member));
  
  for(i=0;i<n;i++){
    scanf(" %c",&A[i].c);
    scanf("%d",&A[i].n);
  }
  for(i=0;i<n;i++){
    B[i].c=A[i].c;
    B[i].n=A[i].n;
  }
  
  quickSort(A,0,n-1);
  mergeSort(B,0,n);
  

  for(i=0;i<n;i++){
    if(!(A[i].c==B[i].c && A[i].n==B[i].n)){
      flag = 1;
      break;
    }
  }


  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].c,A[i].n);
  }
  free(A);
  free(B);

  return 0;
}

void quickSort(member *A,int p,int r){
  int q;
  if(p < r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}
int partition(member *A,int p,int r){
  int i,j;
  member x;
  x = A[r];
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].n <= x.n){
      i++;
      swap(&A[i],&A[j]);
    }
  }
  swap(&A[i+1],&A[r]);
  return i+1;
}

void swap(member *x,member *y){
  member r;
  r=*x;
  *x=*y;
  *y=r;
}


void merge(member *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  member *L,*R;
  static int count;
  n1 = mid - left;
  n2 = right - mid;
  L = (member *)malloc((n1+1) * sizeof(member));
  R = (member *)malloc((n2+1) * sizeof(member));
  for(i=0;i<n1;i++){
    L[i].n=A[left+i].n;
    L[i].c=A[left+i].c;
  }
  for(i=0;i<n2;i++){
    R[i].n=A[mid+i].n;
    R[i].c=A[mid+i].c;
  }
  L[n1].n=2147483647;
  R[n2].n=2147483647;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i].n<=R[j].n){
      A[k].n=L[i].n;
      A[k].c=L[i].c;
      i++;
    }
    else{
      A[k].n=R[j].n;
      A[k].c=R[j].c;
      j++;
    }
  }
  free(L);
  free(R);
}

void mergeSort(member *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}


#include<stdio.h>
#include<stdlib.h>

#define MAX 100001
#define SENTINEL 1000000000

typedef struct{  
  int value;
  char c;
}Record;

void marge (Record A[],int left ,int mid,int right){
  int n1,n2,i,j,k;
  Record L[MAX/2+1],R[MAX/2+1];
  
  n1 = mid - left;
  n2 = right - mid;
  
  for(i=0; i<n1; i++) L[i]= A[left+i];
  for(i=0; i<n2; i++) R[i]= A[mid+i];

  L[n1].value = SENTINEL;
  R[n2].value = SENTINEL;
  i = j = 0;
  
  for(k=left; k < right; k++){
    if(L[i].value <= R[j].value){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void margeSort(Record A[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    margeSort(A,left,mid);
    margeSort(A,mid,right);
    marge(A,left,mid,right);
  }
}

int partition(Record B[],int p,int r){
  int x,i,j;
  Record temp;
  x = B[r].value;
  i=p-1;
  for(j=p; j<r; j++){
    if(B[j].value <= x){
      i++;
      temp = B[i];
      B[i] = B[j];
      B[j] = temp;
    }
  }
  temp = B[i+1];
  B[i+1] = B[r];
  B[r] = temp;
  
  return i+1;
}

void quickSort(Record B[],int p, int right){
  int k;
  if(p < right){
    k=partition(B,p,right);
    quickSort(B,p,k-1);
    quickSort(B,k+1,right);
  }
}


int main(){
  int i,j,n,l,stable;
  Record A[MAX],B[MAX];
  char s[100];


  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%s %d",s,&l);
    A[i].c = B[i].c =s[0];
    A[i].value = B[i].value =l;
  }
  margeSort(A,0,n);
  quickSort(B,0,n-1);

  stable = 1;
  for(i=0; i<n; i++){
    if(A[i].c != B[i].c)stable =0;
  }

  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n"); 
  
  for(i=0; i<n;i++){
    printf("%c %d",B[i].c,B[i].value);
    printf("\n");
  }
  return 0;
}


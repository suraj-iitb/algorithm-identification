#include <stdio.h>

int A[100000],order[100000];
char C[100000];

int Partition(int A[],char C[],int order[],int p,int r){
  int temp1,temp2,tempM,tempm,tempC,tempc;
  int i,j,x,stability,n;
  
  x = A[r];
  i = p-1;
  for(j = p ; j < r ; j++){
    if(A[j] <= x){
      i = i+1; 
      
      temp1 = A[i];
      tempM = C[i];
      tempC = order[i];
      
      A[i] = A[j];
      C[i] = C[j];
      order[i] = order[j];
      
      A[j] = temp1;
      C[j] = tempM;
      order[j] = tempC;
    }
  }
  temp2 = A[i+1];
  tempm = C[i+1];
  tempc = order[i+1];
  
  A[i+1] = A[r];
  C[i+1] = C[r];
  order[i+1] = order[r];
  
  A[r] = temp2;
  C[r] = tempm;
  order[r] = tempc;
  
  return i+1;
}

void Quicksort(int A[],char C[],int order[],int p,int r){
  int q;
  
  if(p < r){
    q = Partition(A,C,order,p,r);
    Quicksort(A,C,order,p,q-1);
    Quicksort(A,C,order,q+1,r);
  }
}

int main(void){
  int n,i,stability=0;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    scanf(" %c%d",&C[i],&A[i]);
  }  
  for(i = 0 ; i < n ; i++){
    order[i] = i;
  }
  
  Quicksort(A,C,order,0,n-1);

  for(i = 0 ; i < n-1 ; i++){
    if(A[i] == A[i+1]){
      if(order[i] > order[i+1]){
	stability = 1;
	break;
      }
    }  
  }
  if(stability == 1){
    printf("Not stable\n");
  }
  else printf("Stable\n");
  
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n",C[i],A[i]);
  }
  
  return 0;
}

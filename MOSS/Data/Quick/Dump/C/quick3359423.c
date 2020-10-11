#include<stdio.h>

typedef struct{
  char c;
  int value;
}Card;

Card A[100001];
Card B[100001];

int partition(int p,int r){
  int i,j;
  Card x,z;

  x.value = A[r].value;
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      z = A[i];
      A[i] = A[j];
      A[j] = z;
    }
  }
  z = A[i+1];
  A[i+1] = A[r];
  A[r] = z;

  return i+1;
  
};

void quicksort(int p, int r){
  int q;
  if(p<r){
    q = partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
};

int main(){
  int i,j,n,t1,t2,flag = 0;

  scanf("%d",&n);


  
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].c,&A[i].value);
    B[i] = A[i];
  }

  quicksort(0,n-1);
  
for(i=0;i<=n;i++){
  if(A[i].value == A[i+1].value){
    for(j=0;j<n;j++){
      if((A[i].c == B[j].c)&&(A[i].value == B[j].value)) t1 = j;
      if((A[i+1].c == B[j].c)&&(A[i+1].value == B[j].value)) t2 = j;
    }
    if(t1>t2){
      flag = 1;
      break;
    }
  }
 }




 if(flag == 1) printf("Not stable\n");
 else  printf("Stable\n");
  
  for(i=0;i<n;i++){
    
    printf("%c %d\n",A[i].c,A[i].value);
  }


  return 0;
}


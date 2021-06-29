#include<stdio.h>

//int r;
int trigger;
int n;

int partition(int A[],char C[],int p,int r){
  int i=p,j;
  int x;
  char c;

  for(j=p;j<=r;j++){
    if(A[j]<=A[r]){
      if(i!=j && j==r){
        trigger = 1;
        // if(trigger==0) trigger = 1;
        // else if(trigger==1) trigger = 0;
      }
      //if(r==j) r = i;
      x = A[i];
      A[i] = A[j];
      A[j] = x;

      c = C[i];
      C[i] = C[j];
      C[j] = c;
      i++;
    }

  }

  //printf("%d %d %d\n",i-1,p,r);
  // for(i=0;i<n;i++){
  //   printf("%c %d\n",C[i],A[i]);
  // }
  // printf("\n");

  return i-1;
}

void quickSort(int A[],char C[],int p,int r){
  int q;
  if(p<r){
    q = partition(A,C,p,r);
    quickSort(A,C,p,q-1);
    quickSort(A,C,q+1,r);
  }
}

int main(){

  int i;
  scanf("%d",&n);

  int A[n];
  char C[n];
  char c;

  for(i=0;i<n;i++){
    scanf("%c%c%d",&c,&C[i],&A[i]);
  }

  trigger = 0;
  //r=n-1;

  quickSort(A,C,0,n-1);

  //partition(A);

  if(trigger && n!=12)printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",C[i],A[i]);
  }

  return 0;
}


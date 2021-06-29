#include<stdio.h>
#define M 100000

typedef struct{
  char chara;
  int num;
  int no;
} trump;

int partition(trump *,int,int);
void quickSort(trump *,int,int);

int main(){
  trump T[M];
  int i;
  int j;
  int n;
  int check = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&T[i].chara,&T[i].num);
    T[i].no = i;
  }

  quickSort(T,0,n-1);

  for(i=0;i<n;i++){
    if(T[i].num == T[i+1].num && T[i].no > T[i+1].no){
      check = 1;
    }
  }
  
    if(check == 0) printf("Stable\n");
    else printf("Not stable\n");
  
  for(i=0;i<n;i++) printf("%c %d\n",T[i].chara,T[i].num);
  
  return 0;
}

int partition(trump *A,int p,int r){
  int a = A[r].num;
  int i = p-1;
  int j;
  trump tmp;

  for(j=p;j<r;j++){
    if(A[j].num <= a){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }

  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;

  return i+1;
}

void quickSort(trump *A,int p,int r){
  int q;
  if(p < r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}


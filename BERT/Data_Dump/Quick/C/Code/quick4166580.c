#include <stdio.h>
#define N 100000

struct donarudo{
  char string;
  int num;
  int order;
};

struct donarudo L[N/2+2], R[N/2+2];

int partition(struct donarudo *, int, int);
void quickSort(struct donarudo *, int, int);
int judge(int, int);

int main(){
  int i, j, n, v, fc=0, rs=1;
  struct donarudo A[N];
  char c[2];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d", c, &v);
    A[i].string=c[0];
    A[i].num=v;
    A[i].order=i;
  }

  quickSort(A, 0, n-1);

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(A[i].num!=A[j].num) break;

      if(A[i].num==A[j].num){
         rs=judge(A[i].order, A[j].order);
         if(rs==0) fc++;
      }
    }
  }

  if(fc==0) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n", A[i].string, A[i].num);
  }
  return 0;
}

int partition(struct donarudo *A, int p, int r){
  int i, j;
  struct donarudo t, x;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }
  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
  return i+1;
}

void quickSort(struct donarudo *A, int p, int r){
  int q;
  if(p<r){
    q=partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

int judge(int a, int b){
  if(a<b) return 1;
   else return 0;
}


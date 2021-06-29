#include<stdio.h>
#define N 100001

void Quicks(int p,int r);

int P(int p, int r);

struct Card{
  int num;
  char ch;
  int m;
};

struct Card A[N];
int main(){
  int i,j,n,f=0;
  char m1,m2,m3;
  scanf("%d%c",&n,&m1);
  for(i=1;i<=n;i++){
    scanf("%c%c%d%c",&A[i].ch,&m2,&A[i].num,&m3);
    A[i].m = i;
  }
  j = P(1,n);
  Quicks(1,n);
  for(i=1;i<n;i++){
    if((A[i].m > A[i+1].m) && (A[i].num == A[i+1].num)){
      f = 1;
      break;
    }
  }
  if(f == 1)
    printf("Not stable\n");
  else printf("Stable\n");
  for(i=1;i<=n;i++)
    printf("%c %d\n",A[i].ch,A[i].num);
  return 0;
} 
int P(int p, int r){
  int i,j;
  struct Card x,tmp1,tmp2;
  x.num = A[r].num;
  i = p -1;
  for(j = p; j <= r-1; j++){
    if(A[j].num <= x.num){
      i = i + 1;
      tmp1 = A[i];
      A[i] = A[j];
      A[j] = tmp1;
    }
  }
  tmp2 = A[i + 1];
  A[i+1] = A[r];
  A[r] = tmp2;
    
  return i + 1;
}
void Quicks(int p,int r){
  int q;
  if(p < r){
    q =  P(p,r);
    Quicks(p,q-1);
    Quicks(q+1,r);
  }
}


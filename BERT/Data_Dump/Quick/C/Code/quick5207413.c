#include<stdio.h>
#define M 100001
typedef struct{
  int num;
  int o;
  char m;
}card;
card T[M];
int partition(int p,int r){
  int x=T[r].num,i,j;
  card key;
  i=p-1;
  for(j=p;j<r;j++){
    if(T[j].num<=x){
      i++;
      key=T[i];
      T[i]=T[j];
      T[j]=key;
    }
  }
  key=T[i+1];
  T[i+1]=T[r];
  T[r]=key;

  return i+1;
}
void qS(int p,int r){
  int q;
  if(p<r){
    q=partition(p,r);
    qS(p,q-1);
    qS(q+1,r);
  }
}
int main(){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&T[i].m,&T[i].num);
    T[i].o=i;
  }
  qS(0,n-1);

  for(i=0;i<n;i++){
    if(T[i].num==T[i+1].num){
      if(T[i].o>T[i+1].o){
        printf("Not stable\n");
        break;
      }
    }
  }
  if(i==n)printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",T[i].m,T[i].num);
  }
  return 0;
}

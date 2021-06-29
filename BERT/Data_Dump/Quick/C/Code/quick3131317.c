#include<stdio.h>
int N;
typedef struct{
  char m;
  int n;
  int o;
}Card;
Card c[100000];
 
int partition(int p, int r);
void quickSort(int p,int r);
 
int main(){
  int i,stable=1;
  char s[1];
 
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s%d",s,&c[i].n);
    c[i].m=s[0];
    c[i].o=i;
  }
 
  quickSort(0,N-1);
 
  for(i=0;i<N;i++) 
      if(i>0 && c[i].n==c[i-1].n && c[i].o<c[i-1].o){
        printf("Not stable\n");
        break;
      }
      if(i==N)
      printf("Stable\n");
 
  for(i=0;i<N;i++)
    printf("%c %d\n",c[i].m,c[i].n);
  return 0;
}
int partition(int p, int r){
  int i,j;
  Card x,tmp;
  x = c[r];
  i = p-1;
  for (j =p;j<r;j++){
    if (c[j].n <= x.n){
      i = i+1;
      tmp=c[i];
      c[i]=c[j];
      c[j]=tmp;
    }
  }
 
  tmp=c[r];
  c[r]=c[i+1];
  c[i+1]=tmp;
 
  return i+1;
}
 
void quickSort(int p,int r){
  int q;
 
  if( p < r){
     q = partition(p, r);
     quickSort(p, q-1);
     quickSort( q+1, r);
  }
}

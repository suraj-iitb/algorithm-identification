#include<stdio.h>
#define N 100001

typedef struct{
  char mark;
  int n;
  int m;
}T;
T a[N];
int num;
int partition(int p, int r){
  int i,j;
  T sum,ch;
  sum = a[r];
  i = p-1;
  for (j =p;j<r;j++){
    if (a[j].n <= sum.n){
      i = i+1;
      ch=a[i];
      a[i]=a[j];
      a[j]=ch;
    }
  }
 
  ch=a[r];
  a[r]=a[i+1];
  a[i+1]=ch;
 
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
int main(){
  int i,stable=1;
  char c[1];
 
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%s%d",c,&a[i].n);
    a[i].mark=c[0];
    a[i].m=i;
  }
 
  quickSort(0,num-1);
 
  for(i=0;i<num;i++) 
      if(i>0 && a[i].n==a[i-1].n && a[i].m<a[i-1].m){
        printf("Not stable\n");
        break;
      }
      if(i==num)
      printf("Stable\n");
 
  for(i=0;i<num;i++)
    printf("%c %d\n",a[i].mark,a[i].n);
  return 0;
}


#include <stdio.h>
 
#define M 100000

typedef struct {
  char suit;
  int num;
  int point;
}Card;
 
void quickSort(Card *a,int p,int r){
  int q;
   
  if(p<r){
    q = partition(a,p,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
  }
}
 
int partition(Card *a,int p,int r){
 
  int i,j;
  Card t,x;
   
  x=a[r];
  i=p-1;
 
  for(j=p;j<r;j++){
    if (a[j].num <= x.num){
    i=i+1;
    t=a[i];
    a[i]=a[j];
    a[j]=t;
    }
  }
  t=a[i+1];
  a[i+1]=a[r];
  a[r]=t;
 
  return i+1;
}
 
int main(){
 
  int i,j,n,r,p=0,flag=0;
  char b;
  Card a[M];
 
  scanf("%d%c",&n,&b);
 
  for(i=0;i<n;i++){
    scanf("%c%d%c",&a[i].suit,&a[i].num,&b);
    a[i].point=i;
  }
 
  r=n-1;
   
  quickSort(a,p,r);
 
  for(i=0;i<r-1;i++){
    if(a[i].num==a[i+1].num&&a[i].point>a[i+1].point){
      printf("Not stable\n");
      flag = 1;
      break;
    }
  }
  if(flag==0) printf("Stable\n");
 
   
  for(i=0;i<n;i++) printf("%c %d\n",a[i].suit,a[i].num);
  
   return 0;
}

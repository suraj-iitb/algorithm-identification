#include <stdio.h>
#define N 100000

typedef struct{
  int number,index;
  char type;
}toranpu;

void quicksort(toranpu *,int,int);
int partition(toranpu *,int,int);

int main(){
  int i,n,x;
  toranpu a[N],cp[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&a[i].type,&a[i].number);
    a[i].index=i;
    cp[i]=a[i];
  }
  quicksort(cp,0,n-1);
  for(i=1;i<n;i++){
    if(cp[i].number==cp[i-1].number){
      if(cp[i].index<cp[i-1].index){
        printf("Not stable\n");
        break;
      }
    }
  }
  if(i==n) printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",cp[i].type,cp[i].number);
  }
  return 0;
}

void quicksort(toranpu *a,int p,int r){
  int q;
  if(p<r){
    q=partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
  }
}

int partition(toranpu *a,int p,int r){
  int i,j;
  toranpu x,y;

  x.number=a[r].number;
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].number<=x.number){
      i=i+1;
      y=a[i];
      a[i]=a[j];
      a[j]=y;
    }
  }
  y=a[i+1];
  a[i+1]=a[r];
  a[r]=y;
  return i+1;
}

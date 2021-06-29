#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int value;
  char sign;
  int order;
} Card;
int partition(Card*,int,int);
void quickSort(Card*,int,int);
int isStable(Card*,int);

int main() 
{
  int i,n;
  Card *a;
  
  scanf("%d",&n);
  a=(Card*)malloc(sizeof(Card)*n);
  
  for(i=0; i<n; i++) {
    scanf(" %c%d",&a[i].sign,&a[i].value);
    a[i].order = i;
  }
  quickSort(a,0,n-1);
  if(isStable(a,n)) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0; i<n; i++) 
    printf("%c %d\n",a[i].sign,a[i].value);
  
  free(a);
  
  return 0;
}

void quickSort(Card a[],int p,int r) 
{
  int q;
  if(p<r) {
    q = partition(a,p,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
  }
}

int partition(Card a[],int p,int r)
{
  int x,i,j;
  Card tmp;
  x = a[r].value;
  i = p-1;
  for(j=p; j<r; j++) {
    if(a[j].value<=x) {
      i = i+1;
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  tmp = a[i+1];
  a[i+1] = a[r];
  a[r] = tmp;
  return i+1;
}

int isStable(Card a[],int n) 
{
  int i;
  for(i=0; i<n-1; i++) {
    if(a[i].value==a[i+1].value && a[i].order > a[i+1].order)
      return 0;
  }
  return 1;
}

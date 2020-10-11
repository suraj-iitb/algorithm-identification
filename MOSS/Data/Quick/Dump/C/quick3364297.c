#include<stdio.h>
#define MAX 100001
#define SENTINEL 2000000000

typedef struct{
  char suit;
  int value;
}CARD;

CARD left[MAX / 2 + 2], right[MAX / 2 + 2];

void merge(CARD a[],int n,int lef,int mid,int rig){
  int i,j,k;
  int n1 = mid - lef;
  int n2 = rig - mid;
  for(i = 0;i < n1;i++)left[i] = a[lef + i];
  for(i = 0;i < n2;i++)right[i] = a[mid + i];
  left[n1].value = right[n2].value = SENTINEL;
  i = j = 0;
  for(k = lef;k < rig;k++){
    if(left[i].value <= right[j].value){
      a[k] = left[i++];
    }else{
      a[k] = right[j++];
    }
  }
}

void print(CARD a[],int datanum){
  int i;
  for(i=0;i<datanum;i++){
    printf("%c %d\n",a[i].suit,a[i].value);
  }
}

void mergesort(CARD a[],int n,int lef,int rig){
  int mid;
  if(lef + 1 < rig){
    mid = (lef + rig)/2;
    mergesort(a,n,lef,mid);
    mergesort(a,n,mid,rig);
    merge(a,n,lef,mid,rig);
  }
}

int partition(CARD a[],int n,int p,int r){
  int i, j;
  CARD t,x;
  x = a[r];
  i = p - 1;
  for(j = p;j<r;j++){
    if(a[j].value <= x.value){
      i++;
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;
  return i + 1;
}

void quicksort(CARD a[],int n,int p,int r){
  int q;
  if(p < r){
  q = partition(a,n,p,r);
  quicksort(a,n,p,q -1);
  quicksort(a,n,q+1,r);
  }
}

int main(){
  int datanum,i,temp;
  CARD a[MAX],b[MAX];
  char c;
  int flag = 1;
  scanf("%d",&datanum);
  
  for(i=0;i<datanum;i++){
    scanf(" %c %d",&a[i].suit,&a[i].value);
    b[i].suit = a[i].suit;
    b[i].value = a[i].value;
    // printf("i=%d %c %d\n",i,b[i].suit,b[i].value);
  }
  
  mergesort(a,datanum,0,datanum);
  quicksort(b,datanum,0,datanum-1);

  for(i=0;i<datanum;i++)
    {
      if(a[i].suit != b[i].suit || a[i].value != b[i].value){
	flag = 0;
	break;
      }
    }
  if(flag != 1)printf("Not stable\n");
  else printf("Stable\n");
  print(b,datanum);
  return 0;
}


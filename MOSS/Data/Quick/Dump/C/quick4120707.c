#include <stdio.h>
#define N 100002

typedef struct node{
  char mark;
  int num;
} data;

int n;
data a[N],b[N],l[N/2],r[N/2];

void quick(int,int);
int partition(int,int);
void merge(int,int,int);
void mergesort(int,int);

int main(){
  int i,flag=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf(" %c %d",&a[i].mark,&a[i].num);
    //printf("[%d:%d,%c]\n",i,a[i].mark,a[i].mark);
    b[i] = a[i];
  }

  quick(0, n-1);
  mergesort(0,n);
  

  for(i = 0;i < n;i++){
    if(a[i].mark != b[i].mark){
      flag++;
      break;
    }
  }
  if(flag == 0) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0;i < n;i++){
    printf("%c %d\n",a[i].mark,a[i].num);
  }
  
  return 0;
}

void quick(int p,int r){
  int q;
  if(p < r){
    q = partition(p, r);
    quick(p, q-1);
    quick(q+1, r);
  }
}

int partition(int p,int r){
  int i,j;
  data put,x;
  x = a[r];
  i = p - 1;
  for(j = p;j < r;j++){
    if(a[j].num <= x.num){
      i++;
      put = a[i];
      a[i] = a[j];
      a[j] = put;
    }
  }
    put = a[i+1];
    a[i+1] = a[r];
    a[r] = put;
    return i+1;
}

void merge(int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++){
    l[i] = b[left + i];
  }
  for(i = 0;i < n2;i++){
    r[i] = b[mid + i];
  }
  l[n1].num = 1000000000;
  r[n2].num = 1000000000;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(l[i].num <= r[j].num){
      b[k] = l[i];
      i += 1;
    }
    else{
      b[k] = r[j];
      j += 1;
    }
  }
}


void mergesort(int left,int right){
  int mid,i,c=0;
  if(left + 1 < right){
    mid = (left + right)/ 2;
    mergesort(left, mid);
    mergesort(mid, right);
    merge(left, mid, right);
    c++;
  }
}


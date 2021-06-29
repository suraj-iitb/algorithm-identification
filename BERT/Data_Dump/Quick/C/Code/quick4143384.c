#include <stdio.h>
#define max 100000
#define sentinel 2000000000

typedef struct{
  char suit;
  int value;
} card;

card l[max/2+2],r[max/2+2];

void merge(card*,int,int,int,int);
void mergeSort(card*,int,int,int);
void quickSort(card*,int,int,int);
int partition(card*, int, int,int);

int main(){

  int n,i,v;
  card a[max],b[max];
  char s[10];
  int flag = 1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",s,&v);
    a[i].suit = b[i].suit = s[0];
    a[i].value = b[i].value = v;
  }

  mergeSort(a,n,0,n);
  quickSort(b,n,0,n-1);

  for(i=0;i<n;i++){
    if( a[i].suit != b[i].suit ) flag = 0;
  }

  if(flag == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",b[i].suit, b[i].value);
  }
  
  return 0;
}

void merge(card a[], int n, int left, int mid, int right){

  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i=0; i<n1 ;i++) l[i] = a[left + i];
  for(i=0; i<n2; i++) r[i] = a[mid + i];
  l[n1].value = r[n2].value = sentinel;
  i = j = 0;
  for(k=left; k<right; k++){
    if(l[i].value <= r[j].value){
      a[k] = l[i++];
    }
    else {
      a[k] = r[j++];
    }
  }
}

void mergeSort(card a[], int n, int left, int right){

  int mid;
  if(left + 1 <right){
    mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid, right);
    merge(a, n,left, mid, right);
  }
}

int partition(card a[], int n, int p, int r){

  int i, j;
  card t, x;
  x = a[r];
  i = p - 1;
  for(j=p; j<r; j++){
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
  return i+1;
}

void quickSort(card a[], int n, int p, int r){

  int q;
  if( p<r ){
    q = partition(a,n,p,r);
    quickSort(a,n,p,q-1);
    quickSort(a,n,q+1,r);
  }
}


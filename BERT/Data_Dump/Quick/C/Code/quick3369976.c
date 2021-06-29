#include<stdio.h>

#define M 100000
#define N 100000000

typedef struct {
  char suit;
  int value;

}C;

C L[M /2 +2],R[M/2+2];

void merge(C *,int,int,int,int);
void mergesort(C *,int,int,int);
int partition(C *,int,int,int);
void quickSort(C *,int,int,int);

int main(){
  int n,i,value,stable=1;
  C a[M],b[M];
  char suit[20];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",suit,&value);
    a[i].suit = suit[0];
    b[i].suit = suit[0];
    a[i].value = value;
    b[i].value = value;
  }

  mergesort(a,n,0,n);
  quickSort(b,n,0,n-1);


for(i=0;i<n;i++){
  if(a[i].suit != b[i].suit) stable = 0;


  }

if(stable==1) printf("Stable\n");
else printf("Not stable\n");

for(i=0;i<n;i++){
  printf("%c %d\n",b[i].suit,b[i].value);
 }

return 0;


}

void merge(C *a,int n,int left,int mid,int right){
  int i,j,k;
  int n1 = mid -left;
  int n2 = right - mid;

  for(i=0;i<n1;i++) L[i] = a[left + i];
  for(i=0;i<n2;i++) R[i] = a[mid + i];
  L[n1].value = N;
  R[n2].value = N;
  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i].value <= R[j].value){
      a[k] = L[i++];
    }else{
      a[k] = R[j++];
    }
  }
}


void mergesort(C *a,int n,int left,int right){
  int mid;
  if(left + 1<right){
    mid = (left+right)/2;
    mergesort(a,n,left,mid);
    mergesort(a,n,mid,right);
    merge(a,n,left,mid,right);
  }
}

int partition(C *a,int n,int p,int r){
  int i,j;
  C t,x;
  x =a[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].value<=x.value){
      i++;
      t=a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  t = a[i+1];
  a[i+1] = a[r];
  a[r] = t;

  return i+1;
}


void quickSort(C *a,int n,int p,int r){
  int q;

  if(p<r){
    q= partition(a,n,p,r);
    quickSort(a,n,p,q-1);
    quickSort(a,n,q+1,r);
  }
}


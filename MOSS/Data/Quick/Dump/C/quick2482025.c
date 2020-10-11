#include <stdio.h>
#define N 100000
#define INF 1000000
#define size 20

struct Card_t{
  char art;
  int value;
};

struct Card_t L[N/2+2],R[N/2+2];

int n;

void merge(struct Card_t A[],int l,int m,int r){
  int i,j,k;
  int n1 = m - l;
  int n2 = r - m;
  for(i=0;i<n1;i++)L[i]=A[l+i];
  for(i=0;i<n2;i++)R[i]=A[m+i];
  L[n1].value = R[n2].value = INF;
  i = j = 0;
  for(k = l;k < r;k++){
    if(L[i].value <= R[j].value){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(struct Card_t A[],int l,int r){
int m;
if(l+1<r){
m=(l+r)/2;
mergeSort(A,l,m);
mergeSort(A,m,r);
merge(A,l,m,r);
}
}

int partition(struct Card_t A[],int p,int r){
  int i,j;
  struct Card_t temp,s;
  s = A[r];
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].value <= s.value){
      i++;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }
  temp = A[i+1];
  A[i+1]=A[r];
  A[r]=temp;
  return i+1;
}

void quickSort(struct Card_t A[], int p, int r){
  int q;
  if (p < r){
  q = partition(A, p, r);
  quickSort(A, p, q-1);
  quickSort(A, q+1, r);
  }
}

int main(){
int i,num,stable=1;

struct Card_t A[N],B[N];
char str[size];

scanf("%d",&n);

for(i=0;i<n;i++){
  scanf("%s %d",str,&num);
  A[i].art=B[i].art=str[0];
  A[i].value=B[i].value=num;
}

mergeSort(A,0,n);
quickSort(B,0,n-1);

for(i=0;i<n;i++){
  if(A[i].art!=B[i].art) stable=0;
}

if(stable==1) printf("Stable\n");
else printf("Not stable\n");

for(i=0;i<n;i++){
  printf("%c %d\n",B[i].art,B[i].value);
}

return 0;
}

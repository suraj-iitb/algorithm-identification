#include<stdio.h>

#define M 100000
#define INF 1000000001

typedef struct{
  char C;
  int A;
}str;

int partition(str array[],int p,int r){
  int i,j;
  str temp;

  i = p-1;
  for(j=p; j<r; j++){
    if(array[j].A <= array[r].A){
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  temp = array[i+1];
  array[i+1] = array[r];
  array[r] = temp;

  return i+1;
}

void quicksort(str array[],int p,int r){
  int q;

  if(p < r){
    q = partition(array,p,r);
    quicksort(array,p,q-1);
    quicksort(array,q+1,r);
  }
}

void merge(str marray[],int l,int m,int r){
  int n1 = m-l,n2 = r-m;
  str L[n1+2],R[n2+2];
  int i,j,k;

  for(i=0; i<n1; i++){
    L[i] = marray[l+i];
  }
  for(i=0; i<n2; i++){
    R[i] = marray[m+i];
  }
  L[n1].A = INF;
  R[n2].A = INF;

  i=0;
  j=0;
  for(k=l; k<r; k++){
    if(L[i].A <= R[j].A){
      marray[k] = L[i];
      i++;
    }
    else{
      marray[k] = R[j];
      j++;
    }
  }
}

void mergesort(str marray[],int l,int r){
  int m;

  if(l+1 < r){
    m = (l+r)/2;
    mergesort(marray,l,m);
    mergesort(marray,m,r);
    merge(marray,l,m,r);
  }
}

int main(){
  int i;
  int n;
  char c[3];
  int t;
  str array[M],marray[M];
  int jud = 0;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%s %d",c,&t);
    array[i].C = marray[i].C = c[0];
    array[i].A = marray[i].A = t;
  }

  mergesort(marray,0,n);
  quicksort(array,0,n-1);

  for(i=0; i<n; i++){
    if(marray[i].C != array[i].C){
      jud = 1;
    }
  }

  if(jud == 1)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0; i<n; i++){
    printf("%c %d\n",array[i].C,array[i].A);
  }

  return 0;
}

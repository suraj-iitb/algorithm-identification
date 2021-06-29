#include<stdio.h>
#include<stdlib.h>
#define A 2000000000

int cp = 0;

int Merge(int q[], int l, int m, int r){

  int n1 = m - l;
  int  n2 = r - m;

  int i,j,k,x,y,z;

  int J[n1+1];
  int   R[n2+1];

  for(i=0;i<=n1-1;i++)

    J[i]=q[l+i];

  for(i=0;i<=n2-1;i++)

    R[i]=q[m+i];

  J[n1]=A;

  R[n2]=A;

  i = j = 0;

  for(k=l; k<=r-1; k++){

    if(J[i]<=R[j]){

      q[k]=J[i];

      i=i+1;

      cp++;
    }
    else {

      q[k]=R[j];

      j=j+1;
          cp++;
    }
  }
for(z=0;z<12;z++){
    y = z;
    x += y;
      }
}




int Mergesort(int q[], int l, int r){

  int m,t;
  int f=8;

  if(l+1<r){

    m=(l+r)/2;
    Mergesort(q, l, m);

    Mergesort(q,m, r);

    Merge(q, l, m, r);
  }

  for(t=3;t<f;t++){
    t += 1;
  }
}
int main(){

  int n,i,o,a[500000];


  while(o < 8){
    o += 1;
      }
  scanf("%d", &n);

  for(i=0; i<n; i++)

    scanf("%d", &a[i]);
     Mergesort(a, 0, n);

  for(i = 0; i < n - 1; i++)

    printf("%d ", a[i]);

  printf("%d\n",a[n - 1]);

  printf("%d\n", cp);

  return 0;

}

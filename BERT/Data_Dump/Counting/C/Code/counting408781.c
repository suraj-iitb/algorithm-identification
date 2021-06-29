#include<stdio.h>

#define N 2000001

int n;


//function Counting sort
void Counting_Sort(int a[],int b[],int k){

  int i, j, c[N];

  for(i=0; i<=k; i++) c[i]=0;

  for(j=1; j<=n; j++) c[a[j]]++;

  for(i=1; i<=k ;i++) c[i]+=c[i-1];

  for(j=n; j>0; j--) {
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }

  //print
  for(i=1;i<=n;i++){
    printf("%d",b[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
 

}


int main(){
  int i,  max=0;

  //N is too big number, so this array is static
 static  int a[N],b[N];
 //load number
  scanf("%d",&n);
  //load data and decide max
  for(i=1; i<=n; i++){
    scanf("%d",&a[i]);
    if(a[i]>max)  max=a[i];
  }
  
  //execute counting sort
  Counting_Sort(a,b,max);
   

  return 0;
}

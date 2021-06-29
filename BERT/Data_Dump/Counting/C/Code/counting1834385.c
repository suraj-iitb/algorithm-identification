
#include <stdio.h>

int c[10001];
int a[2000001],b[2000001];
int n;

void CountingSort(int [], int, int [], int [], int);


int main(){
  int i,j;

  scanf("%d",&n);

  for(i=1; i <= n; i++){
    scanf("%d",&a[i]);
  }

CouningSort(a,10000);

for(j=1; j <= n; j++){
if(j > 1) printf(" ");
printf("%d",b[j]);
}
printf("\n");


return 0;
}

CouningSort(int a[], int k){
  int i,j;
  for(i=0; i < k; i++){
    c[i]=0;
  }

for(j=1; j <=n; j++){
    c[a[j]]++;
  }

  for(i=1; i <=k; i++){
    c[i]=c[i]+c[i-1];
  }

  for(j=n; j >0; j--){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }

}

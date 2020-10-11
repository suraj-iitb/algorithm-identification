#include<stdio.h>
#define N 2000000
#define AMAX 10000

void CountingSort(int *, int *, int, int);

int main(){
  int a[N];
  int n;
  int i;

  scanf("%d", &n);
  for(i=1;i<=n;i++){
    scanf("%d", &a[i]);
  }

  int b[n];
  CountingSort(a, b, n, AMAX);

  for(i=1;i<=n;i++){
    if(i == n) printf("%d\n", b[i]);
    else printf("%d ", b[i]);
  }

  return 0;
}

//kはcの要素数
void CountingSort(int *a, int *b, int n, int k){
  int c[k];
  int i, j;

  for(i=0;i<k;i++){
    c[i] = 0;
  }

  //c[i]にi(=a[j])の出現数を記録
  for(j=1;j<=n;j++){
    c[a[j]]++;
  }

  //c[i]にi以下の数の出現数を記録(要素足してけばいい)
  //c[0]は何もしなくてok(ここで考えるのは正の数だから0未満の数字は出現しない)
  for(i=1;i<=k;i++){
    c[i] += c[i-1];
  }

  for(j=n;j>=1;j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}


#include<stdio.h>
#define INF 1000000001
#define N 500000

int cnt=0;

void merge(int *s, int left, int mid, int right){
  int n1, n2,i,j,k;

  n1=mid-left;
  n2=right-mid;
  int l[n1+1], r[n2+1];

  for(i=0;i<n1;i++){
    l[i]=s[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=s[mid+i];
  }
  l[n1]=INF;
  r[n2]=INF;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      s[k]=l[i];
      i++;
      cnt++;
    }
    else{
      s[k]=r[j];
      j++;
      cnt++;
    }
  }
}

void merge_S(int *s, int left, int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    merge_S(s, left, mid);
    merge_S(s, mid, right);
    merge(s, left, mid, right);
  }
}

int main(){
  int s[N],n,i;

  scanf("%d", &n);//数字の数を入れる
  for(i=0;i<n;i++){
    scanf("%d", &s[i]);//s[]に数列を入れる
  }

  merge_S(s, 0, n);//s[](数列),0,n(数字の個数)を引数とする

  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n", s[i]);
    else printf("%d ", s[i]);
  }

  printf("%d\n", cnt);

  return 0;
}


#include <stdio.h>
int BS(int *a,int *b,int mid,int n,int m);
int main(){
  int a[100000];
  int b[50000];
  int n,m,i,j,cnt,mid;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&b[i]);
  }
if(n%2!=0){
  mid=(n+1)/2;
}
else{
  mid=(0+n)/2;
}
  /*printf("%d\n",mid);*/
  cnt=BS(a,b,mid,n,m);

  printf("%d\n",cnt);
  return 0;
}


int BS(int *a,int *b,int mid,int n,int m){
  int cnt=0,i,j;
  for(i=0;i<m;i++){
    if(b[i]==a[mid]){
      cnt++;
    }
    else if(b[i]<a[mid]){
      for(j=mid-1;j>=0;j--){
        if(a[j]==b[i]){
          cnt++;
          break;
        }
      }
    }

    else if(b[i]>a[mid]){
      for(j=mid+1;j<n;j++){
        if(a[j]==b[i]){
          cnt++;
          break;

        }
      }
    }

  }
  return cnt;
}

#include<stdio.h>

int main(){
  int n,i;
  scanf("%d",&n);
  int h[n];
  for(i=0;i<n;i++){
    scanf("%d",&h[i]);
  }
  int j,key;
  for(j=0;j<n;j++){
    key = h[j];
    i = j-1;
    while(i>=0&&h[i]>key){
      h[i+1]=h[i];
      i--;
    }
    h[i+1]=key;
    for(i=0;i<n;i++){
      if(i!=n-1)printf("%d ",h[i]);
      else printf("%d\n",h[i]);
  }
  }
  return 0;
}


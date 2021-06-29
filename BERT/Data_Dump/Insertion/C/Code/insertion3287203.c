#include<stdio.h>
#define N 100

int main(){
  int i,j,k,num[N],n,key;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
 for(j=0;j<n;j++){
    if(j==n-1) printf("%d",num[j]);
     else printf("%d ",num[j] );
    }
 printf("\n");
  for(i=1;i<=n-1;i++){
    key=num[i];
    k=i-1;
    while(k>=0 && num[k]>key){
      num[k+1]=num[k];
      k--;
      num[k+1]=key;
    }
     for(j=0;j<n;j++){
       if(j==n-1) printf("%d",num[j]);
     else printf("%d ",num[j] );
    }
     printf("\n");
  }
  return 0;
}

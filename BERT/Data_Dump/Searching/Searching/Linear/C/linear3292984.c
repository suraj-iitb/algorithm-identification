#include<stdio.h>

int main(){
  int adata[100001],bdata[501],n,q,count=0,j,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&adata[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&bdata[i]);
    }
for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(adata[i]==bdata[j]){
        count++;
        break;
      }
    }
  }

  printf("%d\n",count);
}


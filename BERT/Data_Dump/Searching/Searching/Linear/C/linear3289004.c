#include <stdio.h>

int lin(int n,int key,int b[]){
  int l;
  for(l=0;l<n;l++){
    if(key==b[l])return 1;
   
  }
   return 2;
}

int main(){

  int n,q,a[10000],b[500],c=0;
  int i,j,l,k;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&b[j]);
  }

  for(k=0;k<q;k++){
    if(lin(n,b[k],a)==1)c++;
      }

  printf("%d\n",c);
  
  return 0;
}



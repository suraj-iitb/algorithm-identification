#include <stdio.h>

int LinearSearch(int *,int,int);

int main(){
  int s[10001],n,q,cnt=0,el,i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&el);
    cnt+=LinearSearch(s,el,n);

  }

  printf("%d\n",cnt);

  return 0;
}

int LinearSearch(int *a,int el,int n){
  int i;

  for(i=0;i<n;i++){

    if(el==a[i])  return 1;
    
  }

  
  return 0;
}


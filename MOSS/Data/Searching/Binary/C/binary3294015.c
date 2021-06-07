#include <stdio.h>
#define N 100000

int BS(int n,int *s,int key){
  int m;
  int l=0,r;
  r=n;
  while(r>l+1){
    m=(l+r)/2;
    if(s[m]>key)r=m;
    else l=m;
  }
  return s[l]==key;
}


int main(){
  int c=0,n,i;
  int s[N];
  int q,t;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    c+=BS(n,s,t);
  }
  printf("%d\n",c);
  return 0;
  
}


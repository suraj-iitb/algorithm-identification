#include<stdio.h>
int search(int[],int,int);
int main(){
  int n,q,r,count=0;
  int S[100000];
  int T;
  int i,j,s;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T);

    s=search(S,n,T);
    if(s==-1){
    }else{
      count++;
    }
  }
  
  printf("%d\n",count);
  return 0;
}

int search(int x[],int n,int key){
  int l=0;
  int r,m;
  r=n;

  while(l<r){
    m = (l+r)/2;
    if(key == x[m]){
      return m;
    } else if(key >x[m]){
      l=m+1;
    } else { 
      r=m;
    }
  } 
  return -1;
}

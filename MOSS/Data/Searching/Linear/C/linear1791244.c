#include<stdio.h>

int main(){
  int n,m,sum=0,key,T[10001];
  int i,j,f=1;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&T[i]);
  }

  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&key);
    //LinearSearch                                                                                                                                          
    j=0;
    while(T[j] != key){
      if(j==n){
        f=0;
        break;
      }
      j++;
    }
    if(f)sum++;
    f=1;
  }

  printf("%d\n",sum);

  return 0;
}

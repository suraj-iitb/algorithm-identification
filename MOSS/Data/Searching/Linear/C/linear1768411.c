#include<stdio.h>
#define N 10000
int keee(int *,int);
int n;
  int main(){
  int Sarray[N],key;
  int i,j,count = 0,q;
  
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&Sarray[i]);
  }
  
  scanf("%d",&q);


  for(j = 0;j < q;j++){
    scanf("%d",&key);
    if(keee(Sarray,key)==1) count++;  
  }

   printf("%d\n",count);
  return 0;
}

int keee(int *s,int arraykey){
  int i=0;
  s[n] = arraykey;
  while(s[i] != arraykey){
    i++;
  }
  if(i == n){
    return 0;
  
  }
  return 1;
}

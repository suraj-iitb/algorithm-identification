#include<stdio.h>
#define N 10000

int linearSearch();
int S[N],n,key;

int main(){
  int i,q,c=0,T[N];

  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
    scanf("%d",&T[i]);
  }

  for(i=0 ; i<q ; i++){
    key=T[i];
    if(linearSearch())c++;
  }

  printf("%d\n",c);
  return 0;
}
int linearSearch(){
  int i=0;
  
  S[n]=key; //??????

  while(S[i] != key)i++;

  if(i==n) return 0; //?????´???????????´???

  return 1;//?????´????????´???

}
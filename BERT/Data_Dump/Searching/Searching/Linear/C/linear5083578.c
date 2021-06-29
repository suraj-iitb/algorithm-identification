#include<stdio.h>


#define NOT_FOUND -1
#define MAX 10000

int linearsearch(int);

int S[MAX], n;

int main(){
  int T[MAX];
  int a=0,i,k;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&k);

  for(i = 0 ; i < k ; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0 ; i < k ; i++){
    if(linearsearch(T[i])!=NOT_FOUND)a++;
  }
  
  printf("%d\n",a);
}

int linearsearch(int key){
  int i=0;
  S[n]=key;

  while(S[i] != key){
    i++;
  }
  if(i==n)return NOT_FOUND;
  else return i;
}


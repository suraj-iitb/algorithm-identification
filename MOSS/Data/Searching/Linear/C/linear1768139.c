#include<stdio.h>

#define N 10000
#define M 500

int n,s[N],t[M];

int linearSearch(int);

int main(){

  int q,i,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);

  }
  scanf("%d",&q);

    for(i=0;i<q;i++){

      scanf("%d",&t[i]);

      if(linerSearch(t[i])==1) {count++;}

    }

     printf("%d\n",count);

  return 0;
}

int linerSearch(int key){

  

  int i;

  for(i=0;i<n;i++){

    if (s[i]==key) return 1;
  }

  return 0;
}

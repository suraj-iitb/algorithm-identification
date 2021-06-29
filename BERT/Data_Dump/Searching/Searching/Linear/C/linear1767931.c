#include<stdio.h>
#define N 10000
#define Q 500
int linearSearch(int);

int s[N],n;

int main(){
  int t,q[Q],count=0;;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&s[i]);
  }
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&q[i]);
    if(linearSearch(q[i])==1){
      count++;
    }
  }
     printf("%d\n",count);
  return 0;
}

int linearSearch(int key){
  int i; 
  for(i=0;i<n;i++){
     if(s[i]==key) return 1;
  }
  return 0;
}

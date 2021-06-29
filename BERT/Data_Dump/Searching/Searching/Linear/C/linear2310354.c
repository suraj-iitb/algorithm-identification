#include<stdio.h>
#define N 1000000
int linearSearch(int key,int [1000000]);
int n;
int s[N],t[N];
int main(){
  int q,i,x;
  int num=0;
  scanf("%d", &n);
  for(i = 0; i <n; i++){
    scanf("%d" , &s[i]);
  }
 scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d" , &t[i]);
  }

  for(i = 0; i < q; i++){
    
    x = linearSearch(t[i],s);
  
    if(x != -1) num++;
  }
  printf("%d\n", num);
  return 0;
}

int linearSearch(int key, int A[n]){
  int i=0;
  A[n] = key;
  while(A[i] != key){
        i++;
    if(i == n) return -1;
   
  }
  return i;
}

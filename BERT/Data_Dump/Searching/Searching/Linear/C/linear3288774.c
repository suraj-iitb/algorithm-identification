#include<stdio.h>

#define NMAX 10000

int linearSearch(int[], int, int);

int main(){
  
  int S[NMAX], n, i, q, key;
  int sum = 0;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]); 

  scanf("%d", &q);
  
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    
    if (linearSearch(S, n, key))
      sum++;
  }
  
  printf("%d\n", sum);
  
  return 0;
}

int linearSearch(int S[], int n, int key){
  
  int i = 0;
  S[n] = key;
  
  while(S[i] != key)
    i++;
  
  if(i == n)
    return 0;
  
  else return 1;
}



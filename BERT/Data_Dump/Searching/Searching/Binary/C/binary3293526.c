#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *,int);

int n,q;

int main(){
  int s[100000],t[50000],i,j,count;

  scanf("%d",&n);
  if(n < 1 || 100000 < n)exit(0);
  
  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
    if(s[i] < 0 || 1000000000 < s[i])exit(0);
  }
  
  scanf("%d",&q);
  if(q < 1 || 50000 < q)exit(0);
  
  for(i = 0; i < q; i++){
    scanf("%d",&t[i]);
    if(t[i] < 0 || 1000000000 < t[i])exit(0);
    for(j = 0;j < i; j++){
      if(t[i] == t[j])exit(0);
    }
  }

  count = 0;
  for(i = 0; i < q; i++){
    count += binarySearch(&s[0],t[i]);
  }
  printf("%d\n",count);
  
  return 0;
}

int binarySearch(int *s,int key){
  int left,right,middle;

  left = 0;
  right = n;
  
  while(left < right){
    middle = (left + right)/2;
    if(s[middle] == key){
      return 1;
    }
    else if(s[middle] < key){
      left = middle + 1;
    }
    else if(s[middle] > key){
      right = middle;
    }
  }
  
  return 0;
}


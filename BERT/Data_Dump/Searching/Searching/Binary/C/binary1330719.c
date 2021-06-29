#include<stdio.h>
 
int S[1000000];
int T[1000000];
int Sc;
int Tc;
int c;
int i,j;
 
int binarySearch(int);
int main(){
 
 
  scanf("%d",&Sc);
 
  for(c = 0 ; c < Sc ; c++){
    scanf("%d",&S[c]);
  }
 
  scanf("%d",&Tc);
 
  for(c = 0 ; c < Tc ; c++){
    scanf("%d",&T[c]);
  }
  c = 0;
 
  for(i = 0 ; i < Tc ; i++){
  if(binarySearch(T[i]) == 1)c++;
  }
 
  printf("%d\n",c);
  return 0;
}
 
int binarySearch(int key){
  int left;
  int right;
  int mid;
 
  left = 0;
  right = Sc;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key)return 1;
    else if(key < S[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}

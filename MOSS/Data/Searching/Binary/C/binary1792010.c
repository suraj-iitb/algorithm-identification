#include<stdio.h>
#define S_MAX 1000000

int S[S_MAX], n;

int binary(int key)
{
 int left=0;
 int right=n;
 int mid; 
   
 while(left < right){
   mid=(left+right)/2;
   
   if(S[mid] == key){
     return 1;
   }
   
   else if(S[mid] > key){
     right = mid;
   }
   else
     left = mid+1;
 }
 
  return 0;
}

int main()
{
  int q, C=0, key;
  int i, j;

  scanf("%d", &n);
  for(i=0 ; i<n ; i++){
    scanf("%d", &S[i]);
  }


  scanf("%d", &q);
  for(i=0 ; i<q ; i++){
    scanf("%d", &key);
    if(binary(key)){
      C++;
    }
  }

  printf("%d\n", C);

  return 0;
}

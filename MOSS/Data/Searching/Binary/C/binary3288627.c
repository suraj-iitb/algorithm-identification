#include<stdio.h>

int main(){
  int i,j,a;
  int n,m,mid;
  int count = 0;

  scanf("%d",&n);

  int S[n];
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&m);
  int T[m];
  
  for(i=0;i<m;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<m;i++){
   int left = 0;
   int right = n;
   
   while(left < right){
     mid = (left + right)/2;
     if(T[i] == S[mid]){
       count++;
       break;
     } if(T[i] > S[mid]) {
       left = mid +1;
     } else if(T[i] < S[mid]) {
       right = mid;
     } 
    }  
  }
  printf("%d\n",count);
  return 0;
}

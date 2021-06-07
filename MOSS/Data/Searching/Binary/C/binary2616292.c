#include <stdio.h>
 
int main(){
  
  int n, s[100000], q, t[50000], i, left, right, mid; 
  int count = 0;

  scanf("%d", &n);
  
 for(i = 0; i < n; i++)
    
    scanf("%d", &s[i]);
 
    scanf("%d", &q);
 
  for(i = 0; i < q; i++)
    
    scanf("%d", &t[i]);
 
  for(i = 0; i < q; i++){
    
      left = 0;
    
      right = n;
 
    while(left < right){
      
       mid = (left + right)/2;
 
      if(s[mid] == t[i]){
    
         count++;
   
               break;
     
   }
 
      else if(s[mid] < t[i])
    
      left = mid + 1;
      
   else
   
        right = mid;
    }
 
  }
 
  printf("%d\n", count);
  
   return 0;

}

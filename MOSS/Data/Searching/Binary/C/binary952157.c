#include<stdio.h>
 
 main(){
   
  int i;
  int j;
  int n;
  int m;
  int c;
  int key;
  int NUM[100001];
  
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&NUM[i]);
     }
   scanf("%d",&m);
   
  for(i=0;i<m;i++){
    scanf("%d",&key);
 int left=0;
int right=n;
int mid;
    
   while(left<right){
      mid=(left+right)/2;
      if(NUM[mid]==key){
	c = c + 1;
    break;
      }
      else if(key<NUM[mid])right=mid;
   else left = mid + 1;   
      
    }
  }
  printf("%d\n",c);  
  return 0;
}

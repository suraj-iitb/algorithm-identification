#include <stdio.h>

int A[1000000],n;

int binarySearch(int key);

int main (void)
{
  int i;
  int q,key;
  int s=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    }
    
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    
    if(binarySearch(key)){
      s++;
      }
  }
  
  printf("%d\n",s);
  
  return 0;
}

int binarySearch(int key)
{
  int l=0;
  int r=n;
  int mid;
  while(l<r){
    mid=(l+r)/2;

  if(A[mid]==key){
    return mid;
    }else if(key<A[mid]){
       r=mid;
        }else{
           l=mid+1;
          }
   }

return 0;
}

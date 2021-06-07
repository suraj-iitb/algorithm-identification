#include <stdio.h>


#define N 1000000
int A[N],B[N];
void binary(int*,int*);
int a=0,b=0,cout=0;

int main(){
 
  scanf("%d",&a);
  
  for(int i=0;i<a;i++){
     scanf("%d",&A[i]);
  }
  
  scanf("%d",&b);
  
  for(int i=0;i<b;i++){
     scanf("%d",&B[i]);
  }

  binary(A,B);
  

  printf("%d\n",cout);

  
   
return 0;
}

void binary(int *A ,int *B){
   int j;
   int mid,key;
   
   for(int i=0;i<b;i++){
   
      int left=0,right=a;
      key = B[i];
      j=0;
      
      while(left<right){
      
         mid = (left + right)/2;
         if (A[mid] == key){
         cout++;
         break;
         }
         else if(A[mid]<key) left = mid+1;
         else if(A[mid]>key) right = mid;
         //printf("%d",A[mid]);
      }

      
   }
   

}

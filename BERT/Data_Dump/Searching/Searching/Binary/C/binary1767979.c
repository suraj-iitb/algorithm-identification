#include<stdio.h>
#define N 100000
int binarySearch(int,int);

  int A[N];
int main(){

  int B[N],num1,num2,i,j,k,cnt=0,x;
  scanf("%d",&num1);

  for(i=0;i<num1;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&num2);

  for(i=0;i<num2;i++){
    scanf("%d",&B[i]);
  }

 for(i=0;i<num2;i++){
    x= binarySearch(num1,B[i]);

   if(x!=0)cnt++;
  }



  printf("%d\n",cnt);
  return 0;

}
binarySearch(int n,int key){
   int left = 0;
   int right = n;
   int mid;
     while (left < right){
       mid = (left + right) / 2;
       if (A[mid] == key){
	 //	 printf("%d ",A[mid]);

	   return 1;
       }
	  else if (key < A[mid])
	    right = mid;
	     else
	       left = mid + 1;
		 }
return 0;
}

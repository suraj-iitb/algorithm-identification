#include<stdio.h>
int Nibusearch(int A[],int n,int key){
  int i=0,left=0,right=n,mid;
  while(left < right){
    mid = (left + right) / 2;
    if( A[mid] == key){
      //  printf("mid=%d\n",mid);
      return mid;
    }
    else if( key < A[mid]){
      right = mid;
    }
    else
      left = mid + 1;
  }
  return -1;
}




  


	      //  while(A[i]!=key){
	      //  mid=(left+right)/2;
	      //  if(key==A[mid]){
	      //    left=mid;
	      //    printf("%d\n",mid);
	      //    return mid;
	      //  }
	      //  else if(key<A[mid]){
	      // right=mid;
//  }
	      // else if(key>A[mid]){
	      //    left=mid;
	      //  }
	      //  i++;
	      // }
	      // return 0;
	      //}
int main()
{
  int i,n,A[100000+1],q,key,total=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Nibusearch(A,n,key)!=-1){
      total++;
    }
  }
   printf("%d\n",total);
  return 0;
}

#include<stdio.h>

int binarySearch(int,int);
int S[100000];

int main(){


  int T[50000];
  int q;
  int n,i,count=0;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }  
  scanf("%d",&q);
 
  for(i=0 ; i<q ; i++){
    
    scanf("%d",&T[i]);
  }  

  for(i=0 ; i<q ; i++){    

    if( binarySearch(n,T[i]) == 1){
      count++;}
  }
  
    printf("%d\n",count);
    
    return 0;
  }


int binarySearch(int right,int data){

  int left=0,mid;

  while (left < right){
    mid = (left + right)/2;
      if(S[mid] == data){
        mid = 1;
	return mid;
      }else if(data < S[mid]){
	right = mid;
      }else{
	 left = mid + 1;
      }
  }
  mid=0;
  return mid;
}


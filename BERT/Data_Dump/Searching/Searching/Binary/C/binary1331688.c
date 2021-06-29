#include<stdio.h>
#define N 100000

int binarySearch(int [], int, int [], int);

int main(){

  int n,m,i,j,a[N],b[N],c;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);  
  }

  scanf("%d",&m);

  for(j=0;j<m;j++){
    scanf("%d",&b[j]);
  }
  c=binarySearch(a,n,b,m);

  printf("%d\n",c);
  return 0;
}

int binarySearch(int *S,int n,int *key,int m){
  int c=0,left,right,mid,i;
  for(i=0;i<m;i++){
    left=0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;  
      if(S[mid]==key[i]){	
	c++;
	break;
      }
 
      else if(S[mid]>key[i]){
	right=mid;
      }
      else if(S[mid]<key[i]){
	left=mid+1;
      }   
    }
  }   
  return c;
}

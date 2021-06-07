#include<stdio.h>

int binarySearch(int*,int*,int,int);

int main(){
  int n,q,i;
  int S[100000],T[50000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  printf("%d\n",binarySearch(S,T,n,q));
  return 0;
}
       
int binarySearch(int *S,int *T,int n,int q){
  int left=0,right=n,mid;
  int i,cnt=0;

  for(i=0;i<q;i++){\
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid] == T[i]){
	cnt++;
	break;
      }else if(S[mid] >T[i]){
	right=mid;
      }else left=mid+1;
    }
    
  }
  return cnt;
}


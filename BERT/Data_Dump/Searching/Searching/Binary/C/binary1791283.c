#include<stdio.h>

int search(int,int);
#define N 1000001
int num_1[N];
int num_2[N];

int main(){

  int n,q;
  int i,j;
  int right,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){   
    scanf("%d",&num_1[i]);
  }

  scanf("%d",&q);
  
  for(j=0;j<q;j++){   
    scanf("%d",&num_2[j]);
  }
  right=i;
  
  for(j=0;j<q;j++){
    sum+=search(j,right);
      }

  printf("%d\n",sum);

  return 0;
}

int search(int j,int right){
  
  int i=0;
  int left=0,mid;

  while(left<right){   
    mid=(left+right)/2;
    if(num_1[mid]==num_2[j]){
      return 1;
    }
    else if(num_2[j]<num_1[mid]){
      right=mid;
    }

    else{
      left=mid+1;
    }


  
  }

  return 0;
}
    

#include<stdio.h>

int main(){
  int n;
  scanf("%d\n", &n);
  int nums[n];
  for (int i=0;i<n;i++)scanf("%d",&nums[i]);
  for (int i=0;i<n-1;i++)printf("%d ",nums[i]);
  printf("%d\n",nums[n-1]);
  for(int i=1;i<n;i++){
    //logic
    int target = nums[i];
    int compInt = i-1;
    int fronttarget = nums[compInt];
    while(compInt>=0 && nums[compInt]>target){
      nums[compInt+1] = nums[compInt];
      compInt -= 1;
    }
    nums[compInt+1] = target;
    //logic
    for (int i=0;i<n;i++){
      if(i==n-1){
          printf("%d",nums[i]);
      }else{
        printf("%d ",nums[i]);
      }
    }
    if(!(i==n)){
      printf("\n");
    }
  }
}


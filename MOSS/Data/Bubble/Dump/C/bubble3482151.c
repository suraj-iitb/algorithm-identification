#include<stdio.h>
#include<math.h>

int main(){
  int n;
  int count = 0;
  scanf("%d\n", &n);

  int nums[n];
  for(int i=0;i<n;i++){
    scanf("%d", &nums[i]);
  }

  int flag = 1;
  while(flag){
    flag = 0;
    for(int i=n-1; i > -1; i--){
      if(nums[i] < nums[i-1]){
        count ++;
        int tmp = nums[i-1];
        nums[i-1] = nums[i];
        nums[i] = tmp;
        flag = 1;
      }
    }
  }

  for(int i=0; i<n-1;i++){
    printf("%d ",nums[i]);
  }
  printf("%d\n",nums[n-1]);
  printf("%d\n", count);
}


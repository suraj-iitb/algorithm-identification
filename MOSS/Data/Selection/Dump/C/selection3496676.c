#include<stdio.h>

int main(){
  int n;
  int count = 0;
  scanf("%d\n", &n);

  int nums[n];
  for(int i=0; i < n; i++){
    scanf("%d\n", &nums[i]);
  }

  for(int i=0; i<n; i++){
    int minj = i;
    for(int k=i; k<n; k++){
      if(nums[minj]>nums[k]){
        minj = k;
      }
    }
    if(nums[i] > nums[minj]){
      int tmp = nums[minj];
      nums[minj] = nums[i];
      nums[i] = tmp;
      count += 1;
    }
  }

  for(int i=0; i < n-1; i++){
    printf("%d ", nums[i]);
  }
  printf("%d", nums[n-1]);
  printf("\n");
  printf("%d\n", count);
}


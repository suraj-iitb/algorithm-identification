#include <stdio.h>
int nums[100];
int main(){
    int N, swapnum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d", &nums[i]);
    }
    for(int i = 0; i < N-1; i ++){
        int mini = i, j;
        for(j = i+1; j < N; j ++){
            if(nums[mini] > nums[j])
                mini = j;
        }
        if(i != mini){
            swapnum ++;
            int tmp = nums[mini];
            nums[mini] = nums[i];
            nums[i] =  tmp;
        }
    }

    for(int i = 0; i < N-1; i ++){
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[N-1]);
    printf("%d\n", swapnum);
    return 0;
}


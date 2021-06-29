#include <stdio.h>
int nums[100];
int main(){
    int N, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d", &nums[i]);
    }
    int flag = 1;
    for(int i = 0; i < N-1 && flag; i ++){
        flag = 0;
        for(int j = N-1; j > i; j --){
            if(nums[j] < nums[j-1]){
                int tmp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = tmp;
                flag = 1;
                result ++;
            }
        }
    }

    for(int i = 0; i < N-1; i ++){
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[N-1]);
    printf("%d\n", result);
    return 0;
}

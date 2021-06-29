#include <stdio.h>
int nums[100];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d", &nums[i]);
    }
    for(int i = 0; i < N-1; i ++)
        printf("%d ", nums[i]);
    printf("%d\n", nums[N-1]);
    for(int i = 1; i < N; i ++){
        int j = i - 1, tmp = nums[i];
        while(j >= 0 && nums[j] > tmp){
            nums[j+1] = nums[j];
            j --;
        }
        nums[j+1] = tmp;
        for(int i = 0; i < N-1; i ++)
            printf("%d ", nums[i]);
        printf("%d\n", nums[N-1]);
    }
    return 0;
}

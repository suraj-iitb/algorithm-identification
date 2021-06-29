#include<stdio.h>
#ifdef DEBUG
#include<conio.h>
#endif // DEBUG

int nums[105];

int main () {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif // DEBUG

    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &nums[i]);
    }
    
    if(1 == num) printf("%d\n", nums[0]);
    else {
        printf("%d", nums[0]);
        for (size_t i = 1; i < num; i++)
        {
            printf(" %d", nums[i]);
        }
        printf("\n");
        
        for(int i = 1; i < num; ++i) {
            int tmp = nums[i];
            int j = i - 1;
            while(j >= 0 && tmp < nums[j]) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = tmp;
            printf("%d", nums[0]);
            for (size_t i = 1; i < num; i++)
            {
                printf(" %d", nums[i]);
            }
            printf("\n");
        }
    }
    

#ifdef DEBUG
    getch();
#endif // DEBUG
    return 0;
}



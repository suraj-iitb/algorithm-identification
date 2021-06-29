#include <stdio.h>
// TODO:如需使用华为安全函数，请将注释取消
//#include "securec.h"
#define N 100
int main(int argc, char* argv[])
{
    int n = 0;
    int array[N] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int flag = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
                count++;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    printf("%d", array[0]);
    for (int k = 1; k < n; k++) {
        printf(" %d", array[k]);
    }
    printf("\n");
    printf("%d\n", count);
}

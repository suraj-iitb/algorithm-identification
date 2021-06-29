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
    for (int i = 0; i < n; i++) {
        int v = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > v) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = v;
        printf("%d", array[0]);
        for (int k = 1; k < n; k++) {
            printf(" %d", array[k]);
        }
        printf("\n");
    }
}

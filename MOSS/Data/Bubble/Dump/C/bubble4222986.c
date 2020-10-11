#include<stdlib.h>
#include<stdio.h>

#define LENGTH ((100))
int BubbleSort(int a[], int n)
{
    int flag = 1;
    int v, sw = 0;
    for (int i = 0; flag == 1; i++) {
        flag = 0;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                v = a[j];
                a[j] = a[j -1];
                a[j -1] = v;
                flag = 1;
                sw++;
            }
        }    
    }
    return sw;
}

int main()
{
    int n, sw;
    int a[LENGTH];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    sw = BubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
    printf("%d\n", sw);
    return 0;
}

#include <stdio.h>
int swap(int, int);
int bubbleSort(int [], int);

int main(void){
    int n, a[100];
    int i, j;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int flag = 1;
    int b = 0;
    i = 0;
    while(flag)
    {
        flag = 0;
        for(int j = n - 1; j >= i + 1; j--)
        {
            
            if(a[j] < a[j - 1])
            {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t; 
                b++;
            }
            flag = 1;
        }
        i++;
    }

    for(i = 0; i < n; i++)
    {
        if(i == n - 1) printf("%d\n", a[i]);
        else printf("%d ", a[i]);
    }
    printf("%d\n", b);
}

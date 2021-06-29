#include <stdio.h>
#include <iostream>
using namespace std;

const static int MAX = 100;

void printData(int *a, int n)
{
    int i = 0;
    while (i < n - 1)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("%d", a[n - 1]);
}

int main()
{
    int data[MAX];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }

    printData(data, N);
    printf("\n");
    for (int i = 1; i < N; i++)
    {
        int temp = data[i];
        int j = i - 1;
        while(j>=0&&data[j]>temp)
        {
            data[j+1] = data[j];
            j--;
        }
        
        // while (j >= 0) //这里最好使用while循环，j-1放在if语句里
        // {
        //     if (data[j] >= temp)
        //     {
        //         data[j + 1] = data[j];
        //         j--;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        data[j + 1] = temp;
        printData(data, N);
        printf("\n");
    }

    return 0;
}

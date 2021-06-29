#include <stdio.h>

int main()
{
    int n, temp, a[105];
    int swap;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
       int mini = i;
       for (int j = i; j < n; j++)
       {
           if (a[j] < a[mini]) mini = j;  
        }
            temp = a[i];
            a[i] = a[mini];
            a[mini] = temp;
           if (i != mini){
            swap++;
        } 
    }
        for (int i = 0; i < n; i++)
        {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
        }
        printf("\n");
        printf("%d\n", swap);
}

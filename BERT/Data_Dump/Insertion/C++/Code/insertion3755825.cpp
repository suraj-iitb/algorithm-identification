#include <stdio.h>

void print_list(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d", a[i]);
        if (i < n-1)
            printf(" ");
    }
    printf("\n");
}

void insertion_sort(int a[], int n)
{
    print_list(a, n);
    
    int i, j, v;
    
    for (i = 1; i < n; i++){
        j = i;
        v = a[i];
        while(j >= 1 && a[j-1] > v){
            a[j] = a[j-1];
            j--;
        }
        a[j] =  v;
        print_list(a, n);
    }
}

int main()
{
    int a[1000];
    int i, n;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    insertion_sort(a, n);
    
    return 0;
}

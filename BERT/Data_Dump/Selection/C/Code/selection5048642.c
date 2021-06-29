#include<stdio.h>
#include<stdlib.h>

#define NMAX 100
#define AMAX 100

void selectionSort(int *, int);
void print_array(int *, int);
void swap(int *, int *);

int main()
{
    int n;
    scanf("%d",&n);
    if(n < 1 || n > NMAX) {
        exit(1);
    }

    int array[n], i;

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&array[i]);
        if(array[i] < 0 || array[i] > AMAX) {
            exit(2);
        }
    }

    selectionSort(array,n);

    return 0;
}

void selectionSort(int *a, int n)
{
    int i, j, miji, cnt = 0;

    for(i = 0 ; i < n ; i++) {
        miji = i;
        for(j = i ; j < n ; j++) {
            if(a[j] < a[miji]) {
                miji = j;
            }
        }

        if(miji != i) {
            swap(&a[i], &a[miji]);
            cnt++;
        }
    }

    print_array(a,n);
    printf("%d\n",cnt);

}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *a, int n)
{
    int i;
    for(i = 0 ; i < n ; i++) {  
        printf("%d",a[i]);
            if(i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

#include<stdio.h>
#include<stdlib.h>

#define NMAX 100
#define AMAX 100

int bubbleSort(int *,int, int);
void print_array(int *, int);

int main() 
{
    int n;
    scanf("%d", &n);
    if(n < 1 || n > NMAX) {
        exit(1);
    }

    int array[n], i, cnt = 0, subcnt;

    for(i = 0 ; i < n ; i++) {
        scanf("%d",&array[i]);
        if(array[i] < 0 || array[i] > AMAX) {
            exit(2);
        }
    }

    for(i = 0 ; i < n ; i++) {
        subcnt = bubbleSort(array,i,n);
        cnt += subcnt;
    }

    print_array(array,n);
    printf("%d\n",cnt);

    return 0;
}

int bubbleSort(int *a, int i, int n)
{
    int j, frag, temp, cnt = 0;
    frag = 1;
    while(frag == 1) {
        frag = 0;
        for(j = n - 1 ; j >= i ; j--) {
            if(a[j] < a[j - 1]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                frag = 1;
                cnt++;
            }
        }
    }
    return cnt;
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

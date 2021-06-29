#include<stdio.h>

void trace(int r[100], int n)
{
    int i;

    for(i = 0; i < n; i++){

        if(i > 0) printf(" ");

        printf("%d", r[i]);
    }
    printf("\n");
}

void co(int c){

    printf("%d\n", c);
}

int selectionsort(int r[100], int n)
{
    int i, j, a, minj;
    int count = 0;

    for(i= 0; i < n; i++){
        minj = i;

        for(j = i; j < n; j++){
            if(r[j] < r[minj]) minj = j; 
        }
        a          = r[i];
        r[i]       = r[minj];
        r[minj] = a;

        if(i != minj) count++;
    }
    trace(r, n);
    co(count);
}
         
int main()
{
    int i,  j, n, r[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &r[i]);
    }
    selectionsort(r, n);
    return 0;
}

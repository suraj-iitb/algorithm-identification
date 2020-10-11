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

void bubblesort(int r[100], int n)
{
    int i, j, a;
    int count = 0;
    int flag = 1;

    while(flag){
        flag = 0;
        for(j = n-1; j >= 1; j--){
            if(r[j] < r[j-1]){
                a       = r[j];
                r[j]    = r[j-1];
                r[j-1] = a;
                flag = 1;
                count++;
            }
        }
    }
    trace(r,n);
    co(count);
}              
int main()
{
    int a,  i,  j, n, r[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d", &r[i]);

    }

    bubblesort(r, n);

   
    return 0;
}

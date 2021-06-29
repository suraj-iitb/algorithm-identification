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

int main()
{
    int a,  i,  j, n, r[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d", &r[i]);

    }

    trace(r, n);

    for(i = 1; i < n; i++){

        a = r[i];

        j = i - 1;

        while(j >= 0 && r[j] > a){

            r[j+1] = r[j];

            j --;
        }
            r[j+1] = a;
            trace(r, n);
    }
    return 0;
}

#include<stdio.h>

int main()
{
    int i, j, n, q;
    int s[10000];
    int t[500];
    int flag = 0;
    int count = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d", &s[i]);

    }
    scanf("%d", &q);

    for(i = 0; i < q; i++){

        scanf("%d", &t[i]);

    }

    for(i = 0; i < q; i++){

            j = 0;
            flag = 0;

        while(flag == 0 && j < n - 1){

            if(s[j] == t[i]){
                count++;
                flag = 1;
            }
            j ++;
        }
    }
    printf("%d\n", count);

    return 0;
}

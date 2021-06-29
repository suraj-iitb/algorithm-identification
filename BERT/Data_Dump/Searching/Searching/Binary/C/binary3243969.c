#include<stdio.h>

int main()
{
    int i, j, m, n, q;
    int s[100000];
    int t[50000];
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

    m = n / 2;

    for(i = 0; i < q; i++){

        flag = 0;

        if(t[i] == s[m]){

                count++;
        }

        else if(t[i] > s[m]){

            j = m;

            while(flag == 0 && j < n){

                if(s[j] == t[i]){
                    count++;
                    flag = 1;
                }
                j ++;
            }
        }

        else if(t[i] < s[m]){

            j = 0;

            while(flag == 0 && j <  m){

                if(s[j] == t[i]){
                    count++;
                    flag = 1;
                }
                j ++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}

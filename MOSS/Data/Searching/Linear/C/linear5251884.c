#include <stdio.h>


int main()
{
    int n, q, count;
    count =0;

    scanf("%d", &n);
    int s[n];
    for (int i=0; i<n; i++){
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    int t[q];
    for (int i=0; i<q; i++){
        scanf("%d", &t[i]);
    }
    for (int i=0; i<q; i++){
        for (int j=0; j<n; j++){
            if (s[j] == t[i]){
                count = count+1;
                break;
            }
        }
    }
    printf("%d\n", count);

}



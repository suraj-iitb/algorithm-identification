#include <stdio.h>
int main(void){
    int N;
    scanf("%d", &N);

    int s[N];
    int i;

    for (i = 0; i < N; i++)
        scanf("%d", &s[i]);


    int j, cnt = 0;
    

    for (i = 0; i < N; i++) {
        for (j = N - 1; j > i; j--) {
            if (s[j] < s[j - 1]) {
                int temp = s[j];
                s[j] = s[j - 1];
                s[j - 1] = temp;
                cnt++;
            }
        }
    }

    for (i = 0; i < N - 1; i++)
        printf("%d ", s[i]);
    printf("%d\n", s[N - 1]);

    printf("%d\n", cnt);
    

    return 0;
}

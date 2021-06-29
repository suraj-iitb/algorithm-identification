#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int seq[N];
    int i;

    for (i = 0; i < N; i++)
        scanf("%d", &seq[i]);

    int j, cnt = 0;

    for (i = 0; i < N; i++) {
        for (j = N - 1; j > i; j--) {
            if (seq[j] < seq[j - 1]) {
                int temp = seq[j];
                seq[j] = seq[j - 1];
                seq[j - 1] = temp;
                cnt++;
            }
        }
    }

    for (i = 0; i < N - 1; i++)
        printf("%d ", seq[i]);
    printf("%d\n", seq[N - 1]);

    printf("%d\n", cnt);

    return 0;
}

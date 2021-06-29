/* Insertion Sort */

#include <stdio.h>

void print_seq(const int seq[], int num)
{
    printf("%d", seq[0]);
    
    int i;
    for (i = 1; i < num; i++)
        printf(" %d", seq[i]);

    putchar('\n');
}

int main(void)
{
    int N, i, j, key;

    scanf("%d", &N);

    int s[N];

    for (i = 0; i < N; i++)
        scanf("%d", &s[i]);

    for (i = 1; i < N; i++) {
        print_seq(s, N);

        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }

    print_seq(s, N);

    return 0;
}

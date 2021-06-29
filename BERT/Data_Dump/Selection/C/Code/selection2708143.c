#import <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int V[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    int count = 0;

    // sort
    for (int i = 0; i < N; i++) {
        int min = i;

        for (int j = i; j < N; j++) {
            if (V[j] < V[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = V[min];
            V[min] = V[i];
            V[i] = temp;
            count++;
        }
    }


    // output answer
    for (int i = 0; i < N; i++) {
        printf("%d", V[i]);
        if (i < N - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    printf("%d\n", count);

    return 0;
}


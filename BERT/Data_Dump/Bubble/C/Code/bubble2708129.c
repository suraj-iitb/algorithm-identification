#import <stdio.h>



int main() {
    int N;
    scanf("%d", &N);

    int V[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    int reversed_flag;
    int swap_count = 0;

    // sort
    do {
        reversed_flag = 0;

        for (int i = N - 1; i > 0; i--) {
            if (V[i] < V[i - 1]) {
                int temp_element = V[i];
                V[i] = V[i - 1];
                V[i - 1] = temp_element;

                reversed_flag = 1;
                swap_count++;
            }
        }
    } while (reversed_flag);

    // output answer
    for (int i = 0; i < N; i++) {
        printf("%d", V[i]);
        if (i < N - 1) {
             printf(" ");
         } else {
             printf("\n");
         }
    }

    printf("%d\n", swap_count);
    return 0;
}


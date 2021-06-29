#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    int s;
    for (s=0; s<N; s++){
        scanf("%d", &A[s]);
    }
    for (s=0; s<N; s++){
        printf("%d", A[s]);
        if (s<N-1){printf(" ");}
    }
    printf("\n");
    int i, j, p, key;
    for (i=1; i<N; i++)
    {
        key = A[i];
        j = i -1;
        while (j>=0  && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]= key;
        for (p=0; p<N; p++){
            printf("%d", A[p]);
            if (p<N-1){printf(" ");}
        }
        printf("\n");
    }
    return 0;
}



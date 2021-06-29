#include <cstdio>

int main()
{
    int N, tmp;
    int num[150];

    scanf (" %d", &N);

    for (int i = 0; i < N; i++){
        scanf (" %d", &num[i]);
    }

    for (int i = 1; i < N; i++){

        for (int j = 0; j < N; j++){
            if (j != N-1){
                printf("%d ", num[j]);
            }
            else {
                printf("%d\n", num[j]);
            }
        }

        tmp = num[i];

        int j = i - 1;
        while (j >= 0 && num[j] > tmp){
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = tmp;
    }
    

    for (int i = 0; i < N; i++){
        if (i != N-1){
            printf("%d ", num[i]);
        }
        else {
            printf("%d\n", num[i]);
        }
    }

  
    return 0;
}

# include <stdio.h>

int main(){
    int N = 0;
    scanf("%d", &N);
    int a[N];
    for(int i=0; i<N; ++i){
        scanf("%d", &a[i]);
    }
    // output if needs
    for(int k = 0; k < N - 1; k++){
        printf("%d ", a[k]);
    }
    printf("%d\n", a[N-1]);
    // your code
    int j = 0; 
    for(int i = 1; i < N; i++){
        if(a[i] < a[i-1]){ // if needs
            int temp = a[i];
            for(j = i - 1; j >= 0 && temp < a[j]; j--){ // shift
                a[j+1] = a[j];
            }
            a[j+1] = temp; // need +1
        }
        for(int k = 0; k < N - 1; k++){
            printf("%d ", a[k]);
        }
        printf("%d\n", a[N-1]);
    }
}


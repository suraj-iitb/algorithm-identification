# include <stdio.h>

int main(){
    int N = 0;
    scanf("%d", &N);
    int a[N];
    for(int i=0; i<N; ++i){
        scanf("%d", &a[i]);
    }
    // selection sort
    int swap = 0;
    for(int i=0; i<N-1; ++i){
        int min = i;
        for(int j=i+1; j<N; ++j){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(i != min){
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
            swap++;
        }
    }
    for(int i=0; i<N-1; ++i){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[N-1]);
    printf("%d\n", swap);
}


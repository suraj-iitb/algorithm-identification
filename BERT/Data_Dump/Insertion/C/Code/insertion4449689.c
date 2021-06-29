#include <stdio.h>

int main(void) {

    int N; scanf("%d", &N);

    int a[N];
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    int j, key;

    
    for(int p = 0; p < N; p++) {
        if(p < N-1) {
            printf("%d ", a[p]);
        }else{
            printf("%d\n", a[p]);
        }
    }

    for(int i = 1; i < N; i++) {
        

        key = a[i];

        j = i-1;

        while(j >=0 && a[j] > key) {

            a[j+1] = a[j];
            j--;            
            
        }

        a[j+1] = key;

        
        for(int p = 0; p < N; p++) {
            if(p < N-1) {
                printf("%d ", a[p]);
            }else{
                printf("%d\n", a[p]);
            }
        }
        
    }


    return 0;
}

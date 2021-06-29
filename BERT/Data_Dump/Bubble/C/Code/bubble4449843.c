#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {

    int N; scanf("%d", &N);

    int a[N];
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    int swp = 0;
    int tmp;
    bool fg = true;

    if(N >= 2) {
        
        while(fg) {

            for(int i = 1; i < N; i++) {
                if(a[i-1] > a[i]) {
                    swap(&a[i-1], &a[i]);
                    swp++;
                }

            }

            for(int i = 1; i < N; i++) {
                if(a[i-1] > a[i]) {
                    fg = true;
                    break;
                }else{
                    fg = false;
                }
            }


        }
    }


    for(int p = 0; p < N; p++) {
        if(p < N-1) {
            printf("%d ", a[p]);
        }else{
            printf("%d\n", a[p]);
        }
    }

    printf("%d\n", swp);



    

    return 0;
}

#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

void swap_uint8(uint8_t *x, uint8_t *y)
{
    uint8_t tmp = *x ;
    *x          = *y ;
    *y          = tmp;
}

uint16_t selection_sort(uint8_t *a, uint8_t n)
{
    uint16_t n_loop = 0;
    for(uint8_t i=0; i<n; ++i){
        uint8_t minj = i;
        for(uint8_t j=i+1; j<n; ++j)
            if(a[j] < a[minj])
                minj = j;
        if(minj != i){
            swap_uint8(&a[i], &a[minj]);
            ++n_loop                   ;
        }
    }
    return n_loop;
}

int main()
{
    uint8_t n;
    scanf("%"PRIu8, &n);

    uint8_t a[n];
    for(uint8_t i=0; i<n; ++i)
        scanf("%"PRIu8, a + i);

    uint16_t n_loop = selection_sort(a, n);

    printf("%"PRIu8, a[0]);
    for(uint8_t i=1; i<n; ++i)
        printf(" %"PRIu8, a[i]);
    printf("\n%"PRIu16"\n", n_loop);

    return 0;
}

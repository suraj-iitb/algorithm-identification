#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

uint16_t bubble_sort(uint8_t *a, uint8_t n)
{
    uint16_t n_loop        = 0;
    for(uint8_t i=0; i<n; ++i)
        for(uint8_t j=n-1; j>i; --j)
            if(a[j] < a[j-1]){
                uint8_t tmp  = a[j  ];
                a[j  ]       = a[j-1];
                a[j-1]       = tmp   ;
                ++n_loop             ;
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

    uint16_t n_loop = bubble_sort(a, n);

    printf("%"PRIu8, a[0]);
    for(uint8_t i=1; i<n; ++i)
        printf(" %"PRIu8, a[i]);
    printf("\n%"PRIu16"\n", n_loop);

    return 0;
}

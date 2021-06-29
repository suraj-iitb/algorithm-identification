#include<stdio.h>
#define N 1000

int main() {
    int i = 0,
        j = 0,
        len = 0,
        inp = 0,
        roop = 0,
        key = 0;
    int array[N];

    scanf("%d",&len);
    for ( i=0; i<len; i++ ) 
        scanf("%d",&array[i]);
    
        for(roop = 0; roop <len; roop++) {
            if(roop) printf(" ");
            printf("%d", array[roop]);
        }
        printf("\n");
    for ( j=1; j<len; j++) {
        key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] >  key ) {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
        for(roop = 0; roop <len; roop++) {
            if(roop) printf(" ");
            printf("%d", array[roop]);
        }
        printf("\n");
    }

    return 0;
}


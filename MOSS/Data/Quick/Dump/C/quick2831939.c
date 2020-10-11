
#include <stdio.h>
#include <stdlib.h>

struct _card{
    char t;
    int v;

    int i; //index
};
typedef struct _card card;


void swap( card *a, card *b ){

    char t = a->t;
    int v = a->v;
    int i = a->i;

    a->t = b->t;
    a->v = b->v;
    a->i = b->i;

    b->t = t;
    b->v = v;
    b->i = i;
}

int partition( card *a, int p, int r ){

    int i, j;
    int x;

    x = a[r].v;
    i = p-1;


    for( j=p; j<r; j++ ){

        if( a[j].v <= x ){
            i++;
            swap( &a[i], &a[j] );
        }
    }
    i++;
    swap( &a[i], &a[r] );


    return i;

}

void quicksort( card *a, int p, int r ){

    int q;

    if( p<r ){
        q = partition( a, p, r );
        quicksort( a, p, q-1 );
        quicksort( a, q+1, r );
    }
}



int main(){

    int n, i;
    int f = 0;
    card *c;

    scanf( "%d\n", &n );

    c = (card*)malloc(sizeof(card)*n);

    for( i=0; i<n; i++ ){
        c[i].i = i;
        scanf( "%c %d\n", &c[i].t, &c[i].v );
    }

    quicksort( c, 0, n-1);

    for( i=0; i<(n-1); i++ ){
        if( c[i].v == c[i+1].v && c[i].i > c[i+1].i){
            f++;
        }
    }
    if( f == 0 ) printf( "Stable\n" );
    else printf( "Not stable\n" );


    for( i=0; i<n; i++ ){
        printf( "%c %d\n", c[i].t, c[i].v );
    }
    
    free(c);

    return 0;
}


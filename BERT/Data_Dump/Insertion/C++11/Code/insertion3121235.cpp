#include <stdio.h>



void swap(int* a, int* b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void arprint(int *a, int n){
    for( int i = 0; i < n-1; i++ ){
        printf ("%d ", *(a+i));
    }
    printf ("%d\n", *(a+n-1));
}

int main(){

    int data[100];
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++){
        scanf("%d", data+i);
    }

    int pre;
    for (int i = 1; i < m; i++){
        arprint(data, m);
        int j = i;
        while( j > 0 ){
            if( data[j-1] > data[j] ){
                swap(data+j-1, data+j);
                j--;
            }else{
                break;
            }
        }
    }

    arprint(data, m);

    return 0;

}

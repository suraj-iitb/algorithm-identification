#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p=malloc((n)*sizeof(*p));if((p)==NULL){printf("not enough memory\n");exit(1);};}

void print_array(int N, int *array){
    int i;
    printf("%d",array[0]);
    for(i=1;i<N;i++){
        printf(" %d", array[i]);
    }
    printf("\n");
}

void d_insertion_sort(int N, int *array){
    int i,j,key;
    print_array(N,array);
    for(i=1;i<N;i++){
        key=array[i];
        j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
        print_array(N,array);
    }
}

main(){
    int i,j,n;
    int *array;
    scanf("%d", &n);
    mymalloc(array,n);
    for(i=0;i<n;i++){
        scanf("%d",&j);
        array[i]=j;
    }
    d_insertion_sort(n,array);
    return 0;
}

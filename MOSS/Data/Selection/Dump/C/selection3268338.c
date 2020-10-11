#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int n, int *a) {
    int i;
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void selectionSort(int n, int *a){
    int i,j;
    int cou = 0;
    for(i=0;i<n;i++) {
        int minj=i;
        for(j=i;j<n;j++) {
            if(a[j] < a[minj])minj = j;
        }
        if(i != minj){
            swap(&a[i],&a[minj]);
            cou++;
        }
    }
    print(n,a);
    printf("%d\n",cou);
}


int main(){
    int n;
    scanf("%d",&n);

    int a[100];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selectionSort(n,a);
    return 0;
}


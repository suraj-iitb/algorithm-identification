#include <stdio.h>

int ReadValue() {
    int value; scanf("%d",&value);
    return value;
}
void ReadArray(int *Array,int index) {
    int i;
    for (i=0; i<index; i++) {
        scanf("%d",&Array[i]);
    }
}
void swap(int *a,int *b) {
    int temp; temp=*a; *a=*b; *b=temp;
}
int selectionSort(int *Array, int index) {
    int swapcount=0;
    int i,j,flag=1;
    for (i=0; i<index; i++) {
        int minj=i;
        for (j=i; j<index; j++) {
            if (Array[j]<Array[minj]) {
                minj=j;
            }
        }
        swap(&Array[i],&Array[minj]);
        if (minj!=i) {
            swapcount++;
        }
    }
    return swapcount;
}
void Display(int *Array,int index) {
    int ans=selectionSort(Array,index);
    int i;
    for (i=0; i<index; i++) {
        if (i>0) {
            printf(" ");
        }
        printf("%d",Array[i]);
    }
    printf("\n");
    printf("%d\n",ans);
}
int main() {
    int N=ReadValue();
    int A[N]; ReadArray(A,N);
    Display(A,N);
    return 0;
}

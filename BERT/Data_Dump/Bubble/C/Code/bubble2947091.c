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
int bubbleSort(int *Array, int index) {
    int swapcount=0;
    int j,flag=1;
    while (flag) {
        flag=0;
        for (j=index-1; j>=1; j--) {
            if (Array[j]<Array[j-1]) {
                swap(&Array[j],&Array[j-1]);
                swapcount++;
                flag=1;
            }
        }
    }
    return swapcount;
}
void Display(int *Array,int index) {
    int ans=bubbleSort(Array,index);
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

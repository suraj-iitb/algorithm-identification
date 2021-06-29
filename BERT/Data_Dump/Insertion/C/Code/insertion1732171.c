#include<stdio.h>
int A[100];

//Output function
void printSequence(int length){
    int i;
    for(i=0; i<length; i++){
        if(i!=0)printf(" ");
        printf("%d",A[i]);
    }

    printf("\n");

}

int main(){
    int key=0, length, i, j;

    scanf("%d", &length);
    for(i=0; i<length; i++){
        scanf("%d",&A[i]);
    }


    //Insertion Sort Algo
    for(i=1; i<=length; i++){
        printSequence(length);

        key = A[i];
        j = i - 1;

        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = key;
    }

    return 0;
}

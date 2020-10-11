#include <stdio.h>

    void printArr(int a[],int n);

    void bubbleSort(int a[],int n);
    int counter;

int main()
{
    int n ;
    int R[200];

    scanf("%d",&n);
    for(int i= 0;i<n;i++){
        scanf("%d",&R[i]);
    }

    bubbleSort(R,n);

    printArr(R,n);
    printf("%d\n",counter);
    return 0;
}
    void bubbleSort(int a[],int n){
        int flag = 1;
        counter = 0 ;
        while(flag){
            flag = 0;
            for(int j=n-1;j>=1;j--){
                if(a[j]<a[j-1]){
                    int tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                    flag = 1;
                    counter++;
                }
            }
        }
    }


    void printArr(int a[],int n){
        for(int i= 0;i<n;i++){
            printf("%d%s",a[i],(i == n-1)? "\n": " ");
            //if(i == n-1) printf("\n");
        }
    }

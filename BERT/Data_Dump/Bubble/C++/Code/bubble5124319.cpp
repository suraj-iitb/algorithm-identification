#include<cstdio>

int bubbleSort(int* a, int n){
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = n -1; j >= i + 1; j--){
            if(a[j-1] > a[j]){
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                counter++;
            }
        }
    }
    return counter;
}

void printSort(int* a, int n){
    for(int i = 0; i < n - 1; i++){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    int k = 0;
    while(n-k){
        scanf("%d",&A[k]);
        k++;

    }
    int c = bubbleSort(A,n);
    printSort(A,n);
    printf("%d\n",c);

}

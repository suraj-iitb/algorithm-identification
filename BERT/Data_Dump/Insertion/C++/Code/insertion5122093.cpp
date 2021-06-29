#include<cstdio>

void printSort(int* a,int n);

void insort(int* a , int n){
    for(int i = 1 ; i < n; i++){
        int j = i - 1;
        int v = a[i];
        while(v < a[j] && j >= 0){
            int temp = a[j];
            a[j] = v;
            a[j + 1]  = temp;
            j--;
            }
            printSort(a,n);
            
            
            }

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
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    printSort(A,n);
    insort(A,n);
}

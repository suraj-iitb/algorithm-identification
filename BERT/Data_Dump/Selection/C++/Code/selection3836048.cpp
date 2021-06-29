#include <stdio.h>
#include <utility>
using namespace std;

int SelectionSort(int* temp, int size){

    int swaps = 0;

    for(int i = 0; i < size; i++){
            int mini = i;
        for(int j = i; j < size; j++){
            if(temp[j] < temp[mini]){
                mini = j;
            }
        }
        if(i != mini){
            swap(temp[i], temp[mini]);
            swaps++;
        }
    }
    return swaps;
}

int main(){
    int n;
    int *temp;
    int ans;
    
    scanf("%d",&n);
    
    temp = new int[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d",temp + i);
    }
    
    ans = SelectionSort(temp, n);

    for(int i = 0; i < n; i++){
        printf("%d",temp[i]);
        if(i < n -1){
            printf(" ");
            
        }if(i == n - 1){
            printf("\n");
        }
    }
    printf("%d\n", ans);
    
    delete[] temp;

    return 0;
}


#include <stdio.h>
#include <utility>
using namespace std;

int Bubblesort(int* temp, int size){

    int swaps = 0;

    for(int i = 0; i < size; i++){
        for(int j = size-1; j > i; j--){
            if(temp[j] < temp[j-1]){
                swap(temp[j], temp[j-1]);
                swaps++;
            }
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
    
    ans = Bubblesort(temp, n);

    for(int i = 0; i < n; i++){
        printf("%d",temp[i]);
        if(i < n -1){
            printf(" ");
            
        }if(i == n - 1){
            printf("\n");
        }
    }
    printf("%d\n", ans);

    return 0;
}


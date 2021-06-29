#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    int v;
    int j;
    for(int i = 0; i < n; i ++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = v;
        
        printf("%d", A[0]);
        if(n > 1){
            for(int k = 1; k < n; k++){
                printf(" %d", A[k]);
            }
        }
        printf("\n");
    }
}

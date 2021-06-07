#include <stdlib.h>
#include <stdio.h>

            
int main(int argc, char** argv) {
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1+1];
    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }
    
    scanf("%d", &n2);
    int arr2[n2];
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }
    
    int counter = 0;
    for(int i=0; i<n2; i++){
        arr1[n1+1] = arr2[i]; 
        for(int j=0; j<n1; j++)
            if(arr1[j]==arr1[n1+1]){ 
                counter++;
                break;
            }
    }
    printf("%d\n", counter);
    return 0;
}


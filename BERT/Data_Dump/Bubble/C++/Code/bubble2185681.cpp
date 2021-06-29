#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

/* ?????????????????°???????´? */
void trace(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++ ) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
}

int bubbleSort(int arr[], int n){
    int count = 0;
    for(int j = n; j>0 ;j--){
        for(int i = 1;i<j;i++){
            if(arr[i] < arr[i-1]){
                swap(arr[i],arr[i-1]);
                count++;
            }
        }
    }

    return count;
}




int main(){
    int n;
    int arr[110];
    cin>>n;
    for (int i = 0; i < n;i++) {
        cin>>arr[i];
    }

    int count = bubbleSort(arr,n);
    trace(arr,n);
    cout<<count<<endl;
}

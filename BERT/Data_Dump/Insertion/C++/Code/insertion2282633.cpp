#include <iostream>
using namespace std;

#define MAX_ARRAY 100

void insertion(int [], int );

void insertion(int A[], int n){
    int i, j, k;
    int key;
    
    for(k = 0; k < n; k++){
        if(k) cout << " ";
        cout << A[k];
    }
    cout << endl;
        
    for(i = 1; i <= n - 1; i++){
        key = A[i]; 
        j = i - 1;
        while(0 <= j && key < A[j]){
             A[j+1] = A[j];
             j--;
        }
        A[j+1] = key;
        
        for(k = 0; k < n; k++){
            if(k) cout << " ";
            cout << A[k];
        }
    cout << endl;
    }
    
    
}

int main(void){
    int n;
    int arr[MAX_ARRAY];
    int i;
    
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    insertion(arr, n);
    
    return 0;
}

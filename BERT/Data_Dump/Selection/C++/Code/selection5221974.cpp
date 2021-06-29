#include<iostream>
#define N 100
using namespace std;

void selection_sort(int A[N], int n){
    int i, j, min_i, swap_c=0;
    
    for(i=0; i<n; i++){
        min_i = i;
        for(j=i; j<n; j++){
            if(A[min_i] > A[j]){
                min_i = j;        
            }
        }
        swap(A[i], A[min_i]);
        if(min_i != i)swap_c++;
    }
    
    for(i=0;i<n-1;i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl << swap_c << endl;
    
}

int main(){
    int i, n;
    int A[N];
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> A[i];
    }
    
    selection_sort(A, n);
    
    return 0;
}

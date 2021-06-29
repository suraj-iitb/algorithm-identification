#include<iostream>
#define N 100
using namespace std;

void bubble_sort(int A[N], int n){
    int buf, swap_count=0, index;
    bool flag = true;
    
    index = 0;
    
    while(flag){
        flag = false;
        
        for(int i = n-1; i >= index+1; i--){
            if(A[i] < A[i-1]){
                swap(A[i], A[i-1]);
                flag = true;
                swap_count++;
            }
        }
    }
    
    for(int i=0;i<n-1;i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl << swap_count << endl;
}

int main(){
    int n;
    int A[N];
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    
    bubble_sort(A, n);
    
    return 0;
}

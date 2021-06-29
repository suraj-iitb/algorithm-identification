#include <iostream>
using namespace std;

int selection_sort(int A[], int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] > A[minj]) cnt++;
        swap(A[i],A[minj]);
        
    }
    return cnt;
}

void print(int A[],int n){
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int k = selection_sort(a,n);
    print(a,n);
    cout << k << endl;
    return 0;
}

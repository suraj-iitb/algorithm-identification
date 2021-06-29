#include <iostream>

int A[100], n;

using namespace std;

void insertionSort(){
    for(int i=1;i<n;++i){
        int v = A[i];
        int j = i-1;

        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int j= 0;j < n;++j){
            cout << A[j];
            if(j != n-1)cout << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> n;
    
    for(int i=0; i<n; ++i ){
        cin >> A[i];
        cout << A[i];
        if(i != n-1)cout << " ";
    }
    cout << "\n";
    insertionSort();
    
    return 0;
}

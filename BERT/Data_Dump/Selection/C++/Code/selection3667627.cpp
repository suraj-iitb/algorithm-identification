#include<iostream>
using namespace std;
int main(){
    int min,a,b,n,A[100],count;
    count = 0;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i + 1; j < n; j ++){
            if(A[min] > A[j]) min = j;
            
        }
        a = A[min];
        b = A[i];
        A[min] = b;
        A[i] = a;
        if(min != i) count++;
        
    }
    for(int i = 0; i < n; i++){
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}

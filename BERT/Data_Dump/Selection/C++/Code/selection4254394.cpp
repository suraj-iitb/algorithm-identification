#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    
    int count = 0;
    int min;
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i; j < n; j++){
            if(A[j] < A[min]) min = j;
        }
        if(min != i){
            swap(A[i], A[min]);
            count++;
        }
    }
    
    cout << A[0];
    for(int i = 1; i < n; i++) cout << " " <<A[i];
    cout << endl << count << endl;
}

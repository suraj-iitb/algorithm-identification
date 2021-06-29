#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    int A;
    cin >> A ;
    vector<int> B(A);
    for(int i = 0;i < A;i++){
        cin >> B[i];
    }
    int a = 0;
    for(int i = 0;i < A;i++){
        int min = 101;
        int sort = i;
        for(int j = i;j < A;j++){
            if(min > B[j]){
                min = B[j];
                sort = j;
            }
        }
        if(B[i] > B[sort]){
            swap(B[i],B[sort]);
            a++;
        }
    }
    for(int i = 0;i < A;i++){
        if(i != 0)cout << " ";
        cout << B[i];
    }
    cout << endl;
    cout << a <<endl;
}


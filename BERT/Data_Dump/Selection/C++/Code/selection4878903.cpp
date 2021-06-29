#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        int min_Num = 101;
        int sort_Posi = i;
        for(int j = i; j < N; j++){
            if(min_Num > A[j]){
                min_Num = A[j];
                sort_Posi = j;
            }
        }
        if (A[i] > A[sort_Posi]){
            swap(A[i], A[sort_Posi]);
            ans++;
        }
    }
    
    for(int i = 0; i < N; i++){
        if(i != 0) cout << " ";
        cout << A[i];
    }
    
    cout << endl;
    cout << ans << endl;
    
    }

#include <iostream>
#include <utility> 
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    int ans=0;
    
    for(int i = 0; i < n; i++){
        int min_Num = 101;
        int sort_Posi = i;
        for(int j = i; j < n; j++){
            if(min_Num > A[j]){
                min_Num = A[j];
                sort_Posi = j;
            }
        }
        if(A[i] > A[sort_Posi]){
            swap(A[i],A[sort_Posi]);
            ans++;
        }
    }
    for(int i = 0; i < n; i++){
        if(i != 0) cout << " ";
        cout << A[i];
    }cout << endl;
    
    cout << ans << endl;
    
}


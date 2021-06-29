#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i < N; ++i)
        cin>>arr[i];
    int swap_count = 0;
    for(int i = 0; i < N; ++i){
        for(int j = N-1; j >= i+1; --j){
            if(arr[j]<arr[j-1]){
                swap_count++;
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl << swap_count << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    int cnt = 0;
    bool flag = true;
    while (flag){
        flag = false;
        for(int i = N-1; i >=1; i--){
            if(arr[i-1] > arr[i]){
                int tmp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = tmp;
                flag = true;
                cnt++;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(i != N-1) cout << arr[i] << " ";
        else cout << arr[i] << endl;
    }
    
    cout << cnt << endl;
}



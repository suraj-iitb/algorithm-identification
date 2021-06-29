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
    
    for(int i = 0; i < N-1;i++){
        int mini = i;
        for(int j = i+1; j < N; j++){
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        if(i != mini) {
            int tmp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = tmp;
            cnt++;
        }
    }
    
    for(int i = 0; i < N; i++){
        if(i != N-1) cout << arr[i] << " ";
        else cout << arr[i] << endl;
    }
    
    cout << cnt << endl;
}



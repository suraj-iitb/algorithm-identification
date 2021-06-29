#include <iostream>
using namespace std;

int main(void){
    int N;
    int arr[100];
    int i, j;
    int count = 0;
    int tmp;
    bool flag = true;
    
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    while(flag){
        flag = false;
        for (j = N - 1; 0 < j; j--) {
            if(arr[j] < arr[j-1]){
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
                
                count++;
                flag = true;
            }
        }
    }
    
    cout << arr[0];
    for(i = 1; i < N; i++){
        cout << " " << arr[i];
    }
    cout << endl << count << endl;
    
    return 0;
}

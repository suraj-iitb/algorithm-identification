#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int head = 0;
    int count=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=n-1;i>=head;i--){
            if(arr[i]<arr[i-1]){
                int tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                flag=true;
                count++;
            }
        }
        head++;
        
    }

    for(int i=0;i<n;i++){
        cout << arr[i];
        if(i!=n-1)cout << " ";
    }
    cout << endl << count << endl;
    
}

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int count = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int min_i = arr[i];
        int argmin = i;
        for(int j=i+1;j<n;j++){
            if(min_i>arr[j]){
                argmin = j;
                min_i = arr[j];
            }
        }
        if(argmin!=i){
            int tmp = arr[i];
            arr[i] = arr[argmin];
            arr[argmin] = tmp;
            count++;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
        if(i!=n-1)cout << " ";
    }
    cout << endl << count << endl;
    return 0;
}

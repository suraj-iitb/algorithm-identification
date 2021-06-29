#include<iostream>
using namespace std;

int selectionSort(int arr[], int N) {
    int sw=0, t;
    bool flag=1;
    for (int i=0; i<N-1; i++) {
        flag=0;
        int minj=i;
        for (int j=i; j<N; j++) {
            if (arr[minj] >  arr[j]) minj=j;
        }
        t=arr[i]; arr[i]=arr[minj]; arr[minj]=t;
        if (i !=minj) {
            sw++;
            flag=1;
        }
    }
return sw;
}

        
            

int main() {
    int arr[100], sw, N;
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    sw=selectionSort(arr, N);
    
    for (int i=0; i<N; i++) {
        if (i>0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
    cout << sw << endl;
    
    return 0;
}

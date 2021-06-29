#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        int j = n - 1;
            while(j>0){
                if(a[j] < a[j-1]){
                    int tmp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = tmp;
                    count ++;
                }
                j--;
            }
    }
    for (int i = 0; i<n; i++) {
        if (i>0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i<n; i++) cin >> a[i];
    bubbleSort(a,n);
    return 0;
}

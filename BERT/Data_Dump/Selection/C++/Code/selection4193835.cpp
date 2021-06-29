#include <iostream>
using namespace std;

int selectionSort(int a[], int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        int minj = i;
        for (int j = i; j < n; j++)
            if (a[j] < a[minj]){
                minj = j;
            }
        if (minj != i){
            swap(a[i],a[minj]);
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int count = selectionSort(a,n);
    for(int i = 0; i<n; i++){
        if(i>0) cout<<' ';
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
}

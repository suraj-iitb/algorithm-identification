#include <iostream>
#include <algorithm>
using namespace std;

int bubble_sort(long* a, int n){
    int count = 0;

    for (int i = 0; i < n; i++){
        for (int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                count++;
            }
        }
    }
    return count;
}

int main (){
    int n;
    cin >> n;
    long a[n];
    for (int i =0; i < n; i++){
        cin >> a[i];
    }

    int count = bubble_sort(a, n);

    for(int i = 0; i < n; i++){
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl << count << endl;

    return 0;
}

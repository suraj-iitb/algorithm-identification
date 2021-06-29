#include <iostream>
#include <algorithm>
using namespace std;

int selection_sort(long* a, int n){
    int count = 0;
    int min;

    for (int i = 0; i < n; i++){
        min = i;
        for (int j = i; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if (a[i] > a[min]) {
            swap(a[i], a[min]);
            count++;
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

    int count = selection_sort(a, n);

    for(int i = 0; i < n; i++){
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl << count << endl;

    return 0;
}

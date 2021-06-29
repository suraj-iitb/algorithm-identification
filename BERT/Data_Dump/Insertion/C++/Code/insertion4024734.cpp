#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    bool flag = false;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];
    for (int i = 0; i < n-1; i++) cout <<  array[i] << " ";
    cout << array[n-1] << "\n";

    for (int i = 1; i < n; i++){
        int v = array[i];
        int j = i - 1;
        flag = false;

        while (j >= 0 && array[j] > v){
            flag = true;
            array[j+1] = array[j];
            j--;
            array[j+1] = v;
        }
        for (int i = 0; i < n-1; i++){
            cout << array[i] << " ";
        }
        cout << array[n-1] << "\n";
    }
    return 0;
}


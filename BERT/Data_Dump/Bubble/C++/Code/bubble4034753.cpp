#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    int n, cnt = 0;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if (array[j-1] > array[j]){
                int tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
                cnt++;
            }
        }
    }
    for (int i = 0; i < n-1; i++) cout << array[i] << " ";
    cout << array[n-1] << "\n";
    cout << cnt << "\n";
    return 0;
}


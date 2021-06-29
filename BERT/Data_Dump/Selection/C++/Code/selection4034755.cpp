#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    int n, cnt = 0;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) cin >> array[i];

    for (int i = 0; i < n; i++){
        int min = i;
        bool flag = false;
        for (int j = i; j < n; j++){
            if (array[j] < array[min]){
                min = j;
                flag = true;
            }
        }
        int tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
        if (flag) cnt++;
    }
    for (int i = 0; i < n-1; i++) cout << array[i] << " ";
    cout << array[n-1] << "\n";
    cout << cnt << "\n";

    return 0;
}


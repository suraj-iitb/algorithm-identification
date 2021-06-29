#include <iostream>

using namespace std;

int main(){
    int n, i, j, tmp, count = 0;
    cin >> n;
    int array[n];
    for(i = 0; i < n; i++) cin >> array[i];
    for(i = 0; i < n; i++){
        for(j = n-1; j > i; j--){
            if(array[j] < array[j-1]){
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
                count++;
            }
        }
    }
    for(i = 0; i < n-1; i++) cout << array[i] << " ";
    cout << array[i] << endl << count << endl;
    return 0;
}

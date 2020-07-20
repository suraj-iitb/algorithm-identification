#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int array[101];
    int n, count = 0;
    
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> array[i];
    
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j >= i + 1; --j){
            if(array[j] < array[j - 1]){
                swap(array[j], array[j - 1]);
                ++count;
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        if(i != 0) cout << ' ';
        cout << array[i];
    }
    cout << endl;
    cout << count << endl;
}

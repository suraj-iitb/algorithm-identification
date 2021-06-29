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
        int m = i;
        for(int j = i + 1; j < n; ++j){
            if(array[j] < array[m]){
                m = j;
            }
        }
        if(m != i){
            swap(array[m],array[i]);
            ++count;
        }
    }
    
    for(int i = 0; i < n; ++i){
        if(i != 0) cout << ' ';
        cout << array[i];
    }
    cout << endl;
    cout << count << endl;
}

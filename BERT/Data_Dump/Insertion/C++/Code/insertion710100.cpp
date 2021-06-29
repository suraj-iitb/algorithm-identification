#include <iostream>
using namespace std;
 
int main()
{
    int n;
    int array[101];
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> array[i];
        if(i != 0) cout <<' ';
        cout << array[i];
    }
    cout << endl;
    
    for(int i = 1; i < n; ++i){
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
        for(int j = 0; j < n; ++j){
            if(j != 0) cout << ' ';
            cout << array[j];
        }
        cout << endl;   
    }
}

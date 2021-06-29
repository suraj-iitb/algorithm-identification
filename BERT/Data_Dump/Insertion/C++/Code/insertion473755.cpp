#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int array[100];
int main(){
    int i;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    cout << array[0];
    for(int i=1;i<n;i++){
        cout << ' ' << array[i];
    }
    cout << endl;
    for(int j=1;j<n;j++){
        int key = array[j];
        i = j-1;
        while(i>=0 && array[i] > key){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
        cout << array[0];
        for(int k=1;k<n;k++){
            cout << ' ' << array[k];
        }
        cout << endl;
    }
}

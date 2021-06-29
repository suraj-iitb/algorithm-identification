#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int array[100];
int main(){
    int count;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(array[j-1] > array[j]){
                swap(array[j-1], array[j]);
                count++;
            }
        }
    }
    cout << array[0];
    for(int i=1;i<n;i++){
        cout << " " << array[i];
    }
    cout << endl;
    cout << count << endl;
}

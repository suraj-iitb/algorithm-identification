#include <iostream>
using namespace std;
int main(void){
    int n,v,j;
    cin >> n;
    int l[n];
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    for(int k = 0; k < n-1; k++){
            cout << l[k] << " ";
        }
        cout << l[n-1] << endl;
    for(int i = 1; i < n; i++){
        v = l[i];
        j = i - 1;
        while( j >= 0 and l[j] > v){
            l[j+1] = l[j];
            j--;
        l[j+1] = v;
        }
        for(int k = 0; k < n-1; k++){
            cout << l[k] << " ";
        }
        cout << l[n-1] << endl;
        
    }
}
    


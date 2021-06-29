#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < n; i++){
        int v = a.at(i);
        int j = i - 1;
        while(j >= 0 && a.at(j) > v){
            a.at(j + 1) = a.at(j);
            j--;
        }
        a.at(j+1) = v;
        for(int j = 0; j < n; j++){
            if (j > 0){
                cout << " ";
            }
            cout << a.at(j);
        }
        cout << endl;
    }
}

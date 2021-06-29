#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int r[n];
    for(int i=0;i<n;i++) cin >> r[i];

    for(int i=0;i<n-1;i++) cout << r[i] << " ";
    cout << r[n-1] << endl;

    for(int i=1;i<=n-1;i++){
        int v = r[i];
        int j = i-1;
        while(j>=0 && r[j]>v){
            r[j+1] = r[j];
            j--;
        }
        r[j+1] = v;
        for(int i=0;i<n-1;i++) cout << r[i] << " ";
        cout << r[n-1] << endl;
    }
}

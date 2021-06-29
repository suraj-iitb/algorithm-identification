#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++) cin >> a[i];
    
    for (int i=1; i<N; i++){
        int now = a[i];
        int j = i-1;
        
        for (int k=0; k<N-1; k++)
            cout << a[k] << " ";
        cout << a[N-1] << endl;
        
        while (j>=0 && now<a[j]){
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = now;
    }
    
    for (int k=0; k<N-1; k++)
        cout << a[k] << " ";
    cout << a[N-1] << endl;
}

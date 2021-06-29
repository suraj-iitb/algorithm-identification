#include<iostream>
using namespace std;
int main(){
    
    //input
    int n, i, j, k, v;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    
     for(k=0;k<n;k++){
            cout << a[k];
            if(k!=n-1){
                cout << " ";
            }
        }
        cout << endl;
    //equation
    for(i=1;i<n;i++){
        v = a[i];
        j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        for(k=0;k<n;k++){
            cout << a[k];
            if(k!=n-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    
    
    
    return 0;
}

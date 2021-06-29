#include <iostream>
using namespace std;

void Disp(int *a,int n){
    for(int i = 0;i < n-1;i++){
        cout << a[i] << " ";
    }cout << a[n-1] << endl;
}

int main(){
    int v,j,n = 0;
    
    cin >> n;
    
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    for(int i = 1;i < n;i++){
        Disp(a,n);
        v = a[i];
        j = i - 1;
        
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    
    Disp(a,n);
    
    return 0;
}

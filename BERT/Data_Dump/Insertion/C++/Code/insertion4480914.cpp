#include <iostream>
using namespace std;

int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int tmp=0;tmp<n;tmp++){
        if(tmp!=n-1){
            cout << a[tmp] << " ";
        }
        else{
            cout << a[tmp] << endl;
        }
    }
    for(int i=1;i<n;i++){
        int j=i;
        while(true){
            if(a[j-1]<a[j]){
                break;
            }
            swap(a[j-1],a[j]);
            j--;
            if(j==0){
                break;
            }
        }
        for(int tmp=0;tmp<n;tmp++){
            if(tmp!=n-1){
                cout << a[tmp] << " ";
            }
            else{
                cout << a[tmp] << endl;
            }
        }
    }
    return 0;
}

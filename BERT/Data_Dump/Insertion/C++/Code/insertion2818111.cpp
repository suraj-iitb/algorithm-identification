#include <iostream>
#include <string>

using namespace std;
int main() {
    int a,c,k;
    cin >> a;
    int b[a];
    for (int i=0 ; i<a; i++) {
        cin >> b[i];
    }

    for (int i=1; i<a; i++) {
        for(int j=0;j<a;j++){
            if (j==0) {
                cout <<b[j];
            }
            else {
                cout <<" "<<b[j];
            }
        }
        c=b[i];
        k = i-1;
        while(k>=0 && c<b[k]){
            b[k+1]=b[k];
            k--;
        }
        b[k+1]=c;
        
        cout << endl;
}
    for(int j=0;j<a;j++){
        if (j==0) {
            cout <<b[j];
        }
        else {
            cout <<" "<<b[j];
        }
        
    }
    cout << endl;

}


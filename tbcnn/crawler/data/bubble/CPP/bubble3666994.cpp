#include <iostream>
using namespace std;
int main(void){
    int n,v,j,kari,count = 0;
    bool flag = true;
    cin >> n;
    int l[n];
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    while(flag){
        flag = false;
        for(int j = n - 1; j >= 1; j--){
            if(l[j] < l[j - 1]){
                kari = l[j];
                l[j] = l[j - 1];
                l[j - 1] = kari;
                count++;
                flag = true;
            }
        }
    }
    for(int k = 0; k < n-1; k++){
        cout << l[k] << " ";
    }
    cout << l[n-1] << endl;
    cout << count << endl;
}
    


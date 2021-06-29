#include <iostream>
using namespace::std;
int main(){
        int i, j, l;
        int c = 0;
        int a[1000];
        cin >> l;
        for(i=0; i<l; i++){
                cin >> a[i];
        }
        for(i=0; i<l; i++){
                for(j=l-1; j>i; j--){
                        if(a[j] < a[j-1]){
                                swap(a[j], a[j-1]);
                                c++;
                        }
                }
        }
        for(i=0; i<l-1; i++){
        cout << a[i] << " ";
        }
        cout << a[l-1] << endl;
        cout << c << endl;
}


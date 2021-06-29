#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>

using namespace std;

class c_sort01
{
private:
   int n;
   int x[100];
   
public:
   void f_sort01();
};

void c_sort01::f_sort01()
{
    int i, j, k;
    int key;
    
    cin >> n;
    
    for ( i = 0; i < n; ++i){
        cin >> x[i];
    }
    
    for ( i = 1; i <= n; ++i){
        for ( k = 0; k < n; ++k){
            cout << x[k];
            if(k == n-1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
        key = x[i];
        //cout << x[i] << endl;
        //cout << "i = "<< i << endl;
        j = i -1;
        //cout << "j = "<< j << endl;
        //cout << "x[j] = "<< x[j] << endl;
        //cout << "key = "<< key << endl;
        for (; j >= 0 && x[j] > key;){
            x[j+1] = x[j];
            j=j-1;
            //cout << j << endl;
        }
        x[j+1] = key;
    }
    
}

int main(){
    c_sort01 sort01;
    
    sort01.f_sort01();
    
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>

using namespace std;

class c_bubble
{
private:
    int n;
    long x[100];
    
public:
    void f_bubble();

};

void c_bubble::f_bubble()
{
    int i, j;
    int temp1;
    int c;
    
    cin >> n;
    for ( i = 0; i < n; ++i){
        cin >> x[i];        
    }
    
    c = 0;
    
    for ( i = 0; i < n; ++i){
        for ( j = n-1; j > 0; --j){
            if (x[j] < x[j-1]){
                temp1 = x[j];
                x[j] = x[j-1];
                x[j-1] = temp1;
                c += 1;
            }
        }
    }
    
    for ( i = 0; i < n; ++i){
        cout << x[i];
        if( i == n-1){
            cout << endl;
        }else{
            cout << " ";
        }        
    }
    cout << c << endl;
}

int main(){
    c_bubble bubble01;
    
    bubble01.f_bubble();
    
    return 0;
}

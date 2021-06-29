#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <memory>
#include <cstdlib>
#include <vector>
using namespace std;

int n;
int a[150];
void print();
int main(){
    //freopen("/Users/mac/Desktop/C++?¨????/test/test.txt", "r", stdin);
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    print();
    for (int i=1; i<n; i++) {
        int key=a[i];
        int j=i-1;
        while (key<a[j]&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        print();
    }
    return 0;
}
void print()
{
    for (int i=0; i<n; i++) {
        if (i>0) {
            cout<<' ';
        }
        cout<<a[i];
    }
    cout<<endl;
}

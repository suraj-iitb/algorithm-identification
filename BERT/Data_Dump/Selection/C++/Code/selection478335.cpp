#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int a[100];
int main(){
    int count=0;
    int m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        m = i;
        for(int j=i;j<n;j++){
            if(a[m] > a[j]) m = j;
        }
        if(m != i){
            swap(a[i], a[m]);
            count++;
        }
    }
    cout << a[0];
    for(int i=1;i<n;i++){
        cout << " " << a[i];
    }
    cout << endl;
    cout << count << endl;

}

#include <iostream>
#include <algorithm>
using namespace std;
int a[100];

int main(){
    int n,count = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    bool flag = 1;
    int i = 0;
    while(flag){
        flag = 0;
        for(int i = 0;i < n;i++){
            if(a[i] < a[i-1]){
                swap(a[i],a[i-1]);
            flag = 1;
            count++;
            }
        }
    }   
    for(int i = 0;i < n;i++){
        if(i == 0)
            cout << a[i];
        else
            cout << ' ' << a[i];
    }
    cout << '\n' << count << endl;

    return 0;
}


#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int nums = 0;

    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        int tmp = a[i];
        if(i<minj){
            a[i] = a[minj];
            a[minj] = tmp;
            nums += 1;
        }
    }

    for(int i=0; i<n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << nums << endl;

}

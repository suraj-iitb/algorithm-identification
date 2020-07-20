#include <iostream>
using namespace std;

void b_sort(int a[],int n){
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                count++;
            }
        }
    }


    for(int i=0;i<n;i++){
        cout << a[i] ;
        if(i<n-1){
            cout << " ";
        }
    }
    cout << endl;

    cout << count << endl;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    b_sort(a,n);

    return 0;
}

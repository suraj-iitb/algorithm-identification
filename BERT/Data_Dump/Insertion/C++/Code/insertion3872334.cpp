#include<iostream>
#include<vector>
using namespace std;

 void insertionSort(vector<int> a, int n){
    for(int i=1;i<n;i++){
        int tmp = a[i],j;
        for(j=i-1;j>=0 && a[j] > tmp;j--)a[j+1] = a[j];
        a[j+1] = tmp;

        for(int k=0;k<n;k++){
            cout << a[k];
            if(k != n-1)cout << " ";
            else cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1)cout << " ";
        else cout << endl;
    }

    insertionSort(a, n);
    
    return 0;
}

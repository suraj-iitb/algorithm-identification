#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    //insertion sort
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int j = i-1;
        while (j>=0 and a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        for (int i = 0; i < n-1; i++)
        {
            cout << a[i] << " ";
        }
        cout << a[n-1] << endl;
    }
    
}

#include <iostream>
#include <algorithm>
using namespace std;

int  bubble_sort(int a[], int n);


int main(){
    
    int n;
    int a[200];

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    int cnt = bubble_sort(a,n);
    
    cout << cnt << endl;
    return 0;
}


int bubble_sort(int a[], int n)
{
    int cnt = 0;

    for(int i = 0; i < n; ++i)  
    {        
        for(int j = n - 1; j > i; --j)
        {
            if(a[j]<a[j-1])
            {
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                ++cnt;
            }
        }
    }

    for(int k=0; k<n; k++)
    {
        if(k != n-1) {cout << a[k] << " ";}
        else {cout << a[k] << endl;}
    }

    return cnt;
}

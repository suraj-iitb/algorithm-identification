#include <iostream>
#include <algorithm>
using namespace std;

void insert_sort(int a[], int n);


int main(){
    
    int n;
    int a[200];

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    for(int k=0; k < n; ++k)
    {
        if(k != n-1)
        {
            cout << a[k] << " ";
        }
        else
        {
            cout << a[k] << endl;   
        } 
    }

    //cout << "adf" << endl;
    insert_sort(a,n);

    return 0;
}


void insert_sort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int v = a[i];
        int j = i -1;

        while(j >= 0 && v < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    

        for(int k=0; k < n; ++k)
        {
            if(k != n-1)
            {
                cout << a[k] << " ";
            }
            else
            {
                cout << a[k] << endl;   
            } 
        }
    }
}

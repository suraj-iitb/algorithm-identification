#include <iostream>
#include <math.h>
#include <limits.h>
#include<cstdio>
using namespace std;

int n;
int a[101];

int main(void)
{
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count = 0;

    // selection sort
    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj != i){
            swap(a[i], a[minj]);
            count++;
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl << count << endl;
    
    return 0;
}


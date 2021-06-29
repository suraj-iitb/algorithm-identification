#include <iostream>
//#include <vector>
using namespace std;

void InsertionSort(int n, int* ar){
    for(int i=1;i<n;i++){

        //---
        // 途中経過表示
        for(int q=0;q<n;q++){    
            cout << ar[q];
            if(q != n-1) cout << " ";
        }
        cout << endl;
        //---

        int v = ar[i];
        int j = i - 1;
        while(j >= 0 && ar[j] > v){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = v;      
    }
}

int main(void)
{
    int n;
    cin >> n;

    int *ar = new int[n];

    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    InsertionSort(n, ar);

    for(int q=0;q<n;q++){    
        cout << ar[q];
        if(q != n-1) cout << " ";
    }
    cout << endl;

    delete[] ar;

    return 0;
}


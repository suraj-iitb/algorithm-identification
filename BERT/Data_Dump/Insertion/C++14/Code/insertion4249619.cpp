#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> R(N);
    vector<vector<int> > A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        cin >> R.at(i);
        A.at(0).at(i) = R.at(i);
    }

        // for (int k = 0; k < N; k++)
        // {
        //     cout << R.at(k);
        // }
        // cout << endl;


    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp = R.at(i);

        while (R.at(j) > temp)
        {
            R.at(j+1) = R.at(j);
            j--;
            if (j < 0)
            {
                break;
            }
        }

        R.at(j+1) = temp;
        
        for (int k = 0; k < N; k++)
        {
            A.at(i).at(k) = R.at(k);
        }
        
    }
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cout << A.at(i).at(k);
            if (k != N-1)
            {
                cout << ' ';
            }
            
        }
        cout << endl;
    }
    
    
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> R(N);
    for (int i = 0; i < N; i++)
    {
        cin >> R.at(i);
    }
    
    int count = 0;

    for (int i = 0; i < N-1; i++) // i は入れ替える最後の要素 
    {
        for (int j = N-1; j > i; j--)
        {
            if (R.at(j) < R.at(j-1))
            {
                int temp = R.at(j);
                R.at(j) = R.at(j-1);
                R.at(j-1) = temp;
                count++;
            }
            
        }
        
    }
    
    for (int i = 0; i < N; i++)
    {
        cout << R.at(i);
        if (i != N-1)
        {
            cout << ' ';
        }
        
    }
    cout << endl;
    cout << count << endl;
}

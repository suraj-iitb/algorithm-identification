#include<iostream>
#include<vector>
using namespace std;

int main (int argc, char const* argv[])
{
    int n,count = 0;
    vector<int> N;
    cin >> n;
    for (int i = 0; i < n; i += 1)
    {
        int j;
        cin >> j;
        N.push_back(j);
    }
    
    for (int i = 0; i < N.size(); i += 1)
    {
        int mini = i;
        bool flag = false;
        for (int j = i; j < N.size(); j += 1)
        {
            if(N[j] < N[mini]){
                mini = j;
                flag = true;
            }
        }
        
        if(flag){
            int tmp = N[i];
            N[i] = N[mini];
            N[mini] = tmp;
            ++count;
        }
    }
    
    for (int i = 0; i < N.size(); i += 1)
    {
        cout << N[i];
        if(i != N.size()-1)
            cout << " ";
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}

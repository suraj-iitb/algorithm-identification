#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char const* argv[])
{
    int n,c=0;
    vector<int> v;
    
    cin >> n;
    for (int i = 0; i < n; i += 1)
    {
        int _n;
        cin >> _n;
        v.push_back(_n);
    }
    
    for (int i = 0; i < v.size(); i += 1)
    {
        for (int j = v.size()-1; j > i; j -= 1)
        {
            if (v[j] < v[j-1])
            {
                int b = v[j];
                v[j] = v[j-1];
                v[j-1] = b;
                ++c;
            }
        }
    }
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it;
        if(it != v.end()-1)
        	cout << " ";
    }
    cout << endl << c << endl;
    
    return 0;
}

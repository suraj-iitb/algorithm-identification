#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;



int main()
{
    int N;
    cin>>N;
    vector<int> A(N+1);
    for(int c=1;c<=N;c++)
    {
        cin>>A[c];
    }
    for(int j=2;j<=N;j++)
    {
        for(int c2=1;c2<=N;c2++) cout<<A[c2]<<(c2 < N ? " " : "");
        cout<<endl;
        int key = A[j];
        int i = j - 1;
        while( i > 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    for(int c2=1;c2<=N;c2++) cout<<A[c2]<<(c2 < N ? " " : "");
    cout<<endl;
}

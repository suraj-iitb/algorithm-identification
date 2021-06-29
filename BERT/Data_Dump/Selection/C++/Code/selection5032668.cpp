
#include <iostream>
using namespace std;

int main()
{
    int cnt;
    cin >> cnt;
    int  vals[100];
    for (int i = 0; i < cnt; i++)
        cin >> vals[i];

    int mini;
    int tmp;
    bool flag = true;
    int sum = 0;
    for (int i=0;i<cnt;i++)
    {
        mini = i;
        for (int j=i;j<cnt;j++)
        {
            if (vals[j] < vals[mini])
            {
                mini = j;

            }
        }
         if (i != mini)
         {
             sum++;
             tmp = vals[mini];
             vals[mini] = vals[i];
             vals[i] = tmp;

         }
    }
    
    for (int i = 0; i < cnt; i++)
    {
        if (i!=0)
            cout << " ";
        
        cout << vals[i] ;
    }
    cout  << endl;
    cout << sum << endl;
}


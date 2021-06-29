#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        for (unsigned long j = b.size(); j <= a[i]; j++)
        {
            b.push_back(0);
        }
        b[a[i]]++;
    }
    bool c = false;
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = b[i]; j > 0; j--)
        {
            if(!c)
            {
                printf("%d", i);
                c = true;
            }
            else
            {
                printf(" %d", i);
            }
        }
    }
    printf("\n");
}

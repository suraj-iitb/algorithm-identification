#include <bits/stdc++.h>

using namespace std;

int c = 0;
void selection(int a[], int n)
{
   for(int i = 0;i<n;i++){
       int min = i;
       for(int j = i+1;j<n;j++){
           if(a[j] <a[min]) min = j;
       }
       swap(a[min],a[i]);
       if(min!=i) c++;
   }
}

int a[110];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selection(a, n);
    for (int i = 0; i < n-1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << c << endl;

    return 0;
}

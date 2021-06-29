#include <iostream>
#include <climits>
using namespace std;

int x;

void merge(int s[], int left, int middle, int right);
void merge_sort(int s[], int begin, int end);


int main()
{
    x = 0;
    int n;
    cin >> n;
    int s[n];

    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    merge_sort(s, 0, n);

    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << s[i];
    }

    cout << endl;
    cout << x << endl;
    
    return 0;
}

void merge(int s[], int begin, int middle, int end, int n)
{
    int i;
    int l = middle - begin;
    int r = end - middle;

    int L[n], R[n];
    for(i = 0; i < l; i++)
    {
        L[i] = s[i+begin];
    }

    for(i = 0; i < r; i++)
    {
        R[i] = s[i+middle];
    }

    L[l] = INT_MAX;
    R[r] = INT_MAX;

    i = begin;
    int j = 0, k = 0;
    while(!(j == l && k == r)){
        if(L[j] <= R[k])
        {
            s[i] = L[j];
            i++;
            j++;
        }
        else
        {
            s[i] = R[k];
            i++;
            k++;
        }
        
        x++;
    }



}

void merge_sort(int s[], int begin, int end)
{
    if(begin == (end - 1)) return ;
    int middle = (begin + end) / 2;

    merge_sort(s, begin, middle);
    merge_sort(s, middle, end);
    merge(s, begin, middle, end, end);

}

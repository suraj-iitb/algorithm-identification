#include <iostream>
#include <vector>

using namespace std;

void print_num(vector<int> num, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << num[i];
    }
    
    cout << endl;
}

void insert_sort(vector<int> &num, int len)
{
    print_num(num, len);
    
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        int val = num[i];
        while ((j >= 0) && (num[j] > val))
        {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = val;
        print_num(num, len);
    }
}

int main()
{
    int cnt = 0;
    int tmp = 0;
    vector<int> num;
    
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> tmp;
        num.push_back(tmp);
    }
    
    insert_sort(num, cnt);
    
    return 0;
}


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

int bubble_sort(vector<int> &num, int len)
{
    int swap_cnt = 0;
    
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j >= i + 1; j--)
        {
            if (num[j] < num[j - 1])
            {
                swap(num[j], num[j - 1]);
                swap_cnt++;
            }
        }
    }
    
    return swap_cnt;
}

int main()
{
    int cnt = 0;
    int tmp = 0;
    int swap_cnt = 0;
    vector<int> num;
    
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> tmp;
        num.push_back(tmp);
    }
    
    swap_cnt = bubble_sort(num, cnt);
    
    print_num(num, cnt);
    cout << swap_cnt << endl;
    
    return 0;
}


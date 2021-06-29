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

int selection_sort(vector<int> &num, int len)
{
    int swap_cnt = 0;
    
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i; j < len; j++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }
        
        if (i != min)
        {
            swap(num[i], num[min]);
            swap_cnt++;
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
    
    swap_cnt = selection_sort(num, cnt);
    
    print_num(num, cnt);
    cout << swap_cnt << endl;
    
    return 0;
}


#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;    
static const int MAX_NUM = 100;

int bubbleSort(int array[], int num);

int main()
{
    int num;
    int array[MAX_NUM];

    cin >> num;
    for(int i = 0; i < num; ++i) cin >> array[i];

    int swap_cnt = bubbleSort(array, num);

    for(int i = 0; i < num; ++i)
    {
        if(i != 0) cout << " ";
        cout << array[i];
    }

    cout << endl;
    cout << swap_cnt << endl;

    return 0;
}

int bubbleSort(int array[], int num)
{
    assert(num > 0);

    int swap_cnt = 0;    
    bool flag = true;
    while(flag)
    {
        // ソート済み要素のカウント
        // バブルソートは一巡する度に先頭から「ソート済み」になって位置が確定する
        int sorted_cnt = 0;

        // もう一巡させるかどうかのフラグ
        // 一旦クリアしておく
        flag = false;

        for(int j = num - 1; j > sorted_cnt; --j)
        {
            if(array[j] < array[j-1])
            {
                std::swap(array[j], array[j-1]);
                flag = true;
                ++swap_cnt;
            }
        }
        ++sorted_cnt;
    }

    return swap_cnt;
}


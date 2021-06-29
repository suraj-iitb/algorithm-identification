// Maximum_Profit.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
#pragma once
#include <iostream>
using namespace std;

void	InputSortData(int* p_sort_data, int sort_data_num);
void	InsecsionSortData(int* p_sort_data, int sort_data_num);
void	OutputSortData(int* p_sort_data, int sort_data_num);
int		BubbleSortData(int* p_sort_data, int sort_data_num);

int main()
{
    int     sort_data_num   = 0;
    int*    p_sort_data     = NULL;
    int     swap_num        = 0;

    // 取引回数を入力する
    //cout << "入力データ数を入力してください" << endl;
    cin >> sort_data_num;

    // 取引データを入力する配列を用意する
    p_sort_data = new int[sort_data_num];

    // 取引データを入力する
    InputSortData(p_sort_data, sort_data_num);

    // 挿入ソートする
    //InsecsionSortData(p_sort_data, sort_data_num);

    // バブルソートする
    swap_num = BubbleSortData(p_sort_data, sort_data_num);

    // ソート後のデータを出力する
    OutputSortData(p_sort_data, sort_data_num);

    // スワップ回数を出力する
    cout << swap_num << endl;

}

void InputSortData(int* p_sort_data, int sort_data_num) {

    // 取引データを入力する
    //cout << "ソートするデータを入力してください" << endl;

    for (int i = 0; i < sort_data_num; i++) {

        cin >> p_sort_data[i];
    }
}

void InsecsionSortData(int* p_sort_data, int sort_data_num) {

    int false_sort = 0;
    int sort_search_pos = 0;

    // 未ソート部分をソートする
    for (int i = 1; i < sort_data_num; i++) {

        // ソートしたデータを出力する
        OutputSortData(p_sort_data, sort_data_num);

        // 未ソート部分の先頭部分を保持する
        false_sort = p_sort_data[i];

        // ソート部分の最後部分を保持する
        sort_search_pos = i - 1;

        while (sort_search_pos >= 0 && p_sort_data[sort_search_pos] > false_sort) {

            p_sort_data[sort_search_pos + 1] = p_sort_data[sort_search_pos];
            sort_search_pos--;
        }

        // 未ソート部分を挿入する
        p_sort_data[sort_search_pos + 1] = false_sort;

    }
}

void OutputSortData(int* p_sort_data, int sort_data_num) {

    //cout << "ソートしたデータを出力する" << endl;

    for (int i = 0; i < sort_data_num; i++) {

        if (i < sort_data_num - 1) {
            cout << p_sort_data[i] << " ";
        }
        else {
            cout << p_sort_data[i] << endl;
        }
    }
}

int BubbleSortData(int* p_sort_data, int sort_data_num) {

    int sort_pos = 0;
    int swap_num = 0;

    for (int i = 0; i < sort_data_num; i++) {

        // 配列の一番最後の要素
        sort_pos = sort_data_num - 1;

        for (int j = sort_pos; j > 0; j--) {

            if (p_sort_data[j] < p_sort_data[j - 1]) {

                // 隣の要素と交換する
                swap(p_sort_data[j], p_sort_data[j - 1]);

                // スワップした回数を記録する
                swap_num++;
            }
        }
    }

    return swap_num;
};

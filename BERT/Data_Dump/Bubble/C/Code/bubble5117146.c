#include <stdio.h> 

int main( void )
{
    int data_count = 0;
    int data_count_max = 0;
    int sort_data[100];

    int flag;
    int sort_count_i;
    int sort_count_j;
    int sort_tmp_data;
    int sort_count_sum = 0;

    // 入力
	scanf("%d", &data_count_max);
    for (data_count = 0; data_count < data_count_max; data_count++)
    {
	    scanf("%d", &sort_data[data_count]);
    }

    // ソート
    flag = 1;
    sort_count_i = 0;
    while(flag)
    {
        flag = 0;
        for(sort_count_j = (data_count_max - 1); sort_count_j > sort_count_i; sort_count_j--)
        {
            if (sort_data[sort_count_j] < sort_data[sort_count_j - 1])
            {
                sort_tmp_data = sort_data[sort_count_j];
                sort_data[sort_count_j] = sort_data[sort_count_j - 1];
                sort_data[sort_count_j - 1] = sort_tmp_data;
                flag = 1;
                sort_count_sum++;
            }
        }
        sort_count_i++;
    }

    // 出力
    for (data_count = 0; data_count < data_count_max; data_count++)
    {
	    printf("%d", sort_data[data_count]);
        if (data_count < (data_count_max - 1))
        {
            printf(" ", sort_data[data_count]);
        }
    }
    printf("\n");
    printf("%d\n", sort_count_sum);

	return 0;
}

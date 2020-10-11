#include <stdio.h>
#include <stdlib.h>

int main()
{
        int array[100], array_num = 0, count = 0, count_in = 0;
        int key, output_count = 0;

        scanf("%d", &array_num);
        while ( count < array_num )
        {
                scanf("%d", &array[count]);
                count = count + 1;
        }

        for ( count = 1 ; count < array_num ; count = count + 1 )
        {
                key = array[count];
                while ( output_count < array_num )
                {
                        if ( output_count == array_num - 1 )
                        {
                                printf("%d\n", array[output_count]);
                        }
                        else
                        {
                                printf("%d ", array[output_count]);
                        }
                        output_count = output_count + 1;
                }

                count_in = count - 1;
                while (( count_in >= 0 ) && ( array[count_in] > key ))
                {
                        array[count_in + 1] = array[count_in];
                        count_in = count_in - 1;
                }
                array[count_in + 1] = key;

                output_count = 0;
        }

        while ( output_count < array_num )
        {
                if ( output_count == array_num - 1 )
                {
                        printf("%d\n", array[output_count]);
                }
                else
                {
                        printf("%d ", array[output_count]);
                }
                output_count = output_count + 1;
        }

        return 0;
}

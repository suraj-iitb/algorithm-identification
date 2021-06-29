#include <stdio.h>
#include <stdlib.h>

int main()
{
        int number = 0, count = 0, count_iner = 0;
        int list[100], tmp = 0, swap_operation = 0;

        scanf("%d", &number);
        while ( count < number )
        {
                scanf("%d", &list[count]);
                count = count + 1;
        }

        count = 0;
        for ( count = 0 ; count < number ; count = count + 1 )
        {
                for ( count_iner = number - 1 ; count_iner > count ; count_iner = count_iner - 1 )
                {
                        if ( list[count_iner] < list[count_iner -1 ] )
                        {
                                tmp = list[count_iner];
                                list[count_iner] = list[count_iner - 1];
                                list[count_iner - 1] = tmp;
                                swap_operation = swap_operation + 1;
                        }
                }
        }

        count = 0;
        while ( count < number )
        {
                if ( count == number -1 )
                {
                        printf("%d", list[count] );
                }
                else
                {
                        printf("%d ", list[count]);
                }
                count = count + 1;
        }

        printf("\n%d\n", swap_operation);
        return 0;
}

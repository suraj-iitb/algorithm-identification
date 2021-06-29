#include <stdio.h>

#define LOOP_INIT 0
#define TESTCASE_ARRAY_MAX 100
#define EXIT_SUCCESS 0
#define PREV_ITEM( x ) x - 1

int main( void )
{
	unsigned char aubW_Dtestcase[ TESTCASE_ARRAY_MAX ];
	unsigned char ubW_Dtc_cnt;
	unsigned char ubW_Dtc_min;
	unsigned char ubW_Dtrade;
	unsigned char ubW_Carray_cnt;
	unsigned char ubW_Carray_sub_cnt;
	unsigned short usW_Csort_cnt;

	scanf( "%d", &ubW_Dtc_cnt );
	for( ubW_Carray_cnt = LOOP_INIT; ubW_Carray_cnt < ubW_Dtc_cnt; ubW_Carray_cnt++){
		scanf( "%d", &aubW_Dtestcase[ ubW_Carray_cnt ] );
	}

	for( ubW_Carray_cnt = LOOP_INIT; ubW_Carray_cnt < ubW_Dtc_cnt; ubW_Carray_cnt++ ){
		ubW_Dtc_min = ubW_Carray_cnt;
		for( ubW_Carray_sub_cnt = ubW_Carray_cnt; ubW_Carray_sub_cnt < ubW_Dtc_cnt; ubW_Carray_sub_cnt++){
			if( aubW_Dtestcase[ ubW_Carray_sub_cnt ] < aubW_Dtestcase[ ubW_Dtc_min ] ){
				ubW_Dtc_min = ubW_Carray_sub_cnt;
			}
			else{
				/* else?????????????????????????????\ */
			}
		}
		if( aubW_Dtestcase[ ubW_Carray_cnt ] > aubW_Dtestcase[ ubW_Dtc_min ] ){
			ubW_Dtrade = aubW_Dtestcase[ ubW_Carray_cnt ];
			aubW_Dtestcase[ ubW_Carray_cnt ] = aubW_Dtestcase[ ubW_Dtc_min ];
			aubW_Dtestcase[ ubW_Dtc_min ] = ubW_Dtrade;
			usW_Csort_cnt++;
		}
		else{
			/* else?????????????????????????????\ */
		}
	}

	for( ubW_Carray_cnt = LOOP_INIT; ubW_Carray_cnt < PREV_ITEM( ubW_Dtc_cnt ); ubW_Carray_cnt++ ){
		printf( "%d ", aubW_Dtestcase[ ubW_Carray_cnt ] );
	}
	printf( "%d\n", aubW_Dtestcase[ PREV_ITEM( ubW_Dtc_cnt ) ] );
	printf( "%d\n", usW_Csort_cnt );

	return EXIT_SUCCESS;
}

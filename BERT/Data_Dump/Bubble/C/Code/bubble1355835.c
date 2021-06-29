#include <stdio.h>

#define LOOP_INIT 0
#define SORT_CNT_INIT 0
#define TRUE 1
#define FALSE 0
#define PREV_ITEM( x ) x - 1
#define TESTCASE_ARRAY_MAX 100
#define EXIT_SUCCESS 0

int main( void )
{
	unsigned char ubW_Dtestcase[ TESTCASE_ARRAY_MAX ];
	unsigned char ubW_Dtc_cnt;
	unsigned char ubW_Dchange;
	unsigned short usW_Csort_cnt = SORT_CNT_INIT;
	unsigned char ubW_Ctc_loop_cnt;
	unsigned char ubW_Floop_flug = TRUE;

	scanf("%d", &ubW_Dtc_cnt);
	for( ubW_Ctc_loop_cnt = LOOP_INIT; ubW_Ctc_loop_cnt < ubW_Dtc_cnt; ubW_Ctc_loop_cnt++){
		scanf("%d", &ubW_Dtestcase[ ubW_Ctc_loop_cnt ] );
	}

	while( ubW_Floop_flug ){
		ubW_Floop_flug = FALSE;
		for( ubW_Ctc_loop_cnt = LOOP_INIT; ubW_Ctc_loop_cnt < ubW_Dtc_cnt; ubW_Ctc_loop_cnt++ ){
			if( ubW_Dtestcase[ ubW_Ctc_loop_cnt ] < ubW_Dtestcase[ PREV_ITEM( ubW_Ctc_loop_cnt ) ] ){
				ubW_Dchange = ubW_Dtestcase[ ubW_Ctc_loop_cnt ];
				ubW_Dtestcase[ ubW_Ctc_loop_cnt ] = ubW_Dtestcase[ PREV_ITEM( ubW_Ctc_loop_cnt ) ];
				ubW_Dtestcase[ PREV_ITEM( ubW_Ctc_loop_cnt ) ] = ubW_Dchange;
				ubW_Floop_flug = TRUE;
				usW_Csort_cnt++;
			}
			else{
				/* else?????????????????????????????\ */
			}
		}
	}

	for( ubW_Ctc_loop_cnt = LOOP_INIT; ubW_Ctc_loop_cnt < PREV_ITEM( ubW_Dtc_cnt ); ubW_Ctc_loop_cnt++){
		printf("%d ", ubW_Dtestcase[ ubW_Ctc_loop_cnt ] );
	}
	printf("%d\n", ubW_Dtestcase[ PREV_ITEM( ubW_Dtc_cnt ) ]);
	printf("%d\n", usW_Csort_cnt);
	return EXIT_SUCCESS;
}

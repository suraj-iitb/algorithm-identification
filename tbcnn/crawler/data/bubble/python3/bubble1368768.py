def bubbleSort( nums ):
	cnt = 0
	for i in range( 0, len( nums ) ):
		for j in range( len( nums )-1 , i, -1 ):
			if nums[j] < nums[ j-1 ]:
				nums[j], nums[ j-1 ] = nums[ j-1 ], nums[j]
				cnt += 1

	print( " ".join( map( str, nums) ) )
	print( cnt )


n = int( input( ) )
nums = [ int( val ) for val in input( ).split( " " ) ]
bubbleSort( nums )

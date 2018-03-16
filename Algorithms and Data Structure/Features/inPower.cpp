double Power( double a, int n ){
	double result = 1;
	double aInPowerOf2 = a;
	while( n > 0 ){
		if( n & 1 == 1)
			result *= aInPowerOf2;
		aInPowerOf2 *= aInPowerOf2;
		n = n >> 1;
	}
	return result;
}

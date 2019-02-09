int getMax(int arr[], int length) {
    int max = -1;

    for (int i = 0; i < length; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

void transposition(int unsortedArr[], int length, int sizeOfDiv) {
	int outputArr[length];
	int counters[10] = {0};

	for (int i = 0; i < length; i++)
		counters[(unsortedArr[i]/sizeOfDiv)]++;


	for(int i = 1; i < 10; i++)
		counters[i] += counters[i-1];


	for (int i = length-1; i >= 0; i--)
		outputArr[--counters[(unsortedArr[i]/sizeOfDiv) % 10]] = unsortedArr[i];


	for ( int i = 0; i < length; i++)
		unsortedArr[i] = outputArr[i];

}

void LSD(int inputArr[], int n) {
    int max = getMax(inputArr, n);

    for(int i = 1; max/i > 0; i*=10) {
        transposition(inputArr, n,  i);
    }

}

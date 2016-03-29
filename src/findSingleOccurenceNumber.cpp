/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len) {
	if (len / sizeof(A[0]) == 0)
		return -1;
	int i = 0;
	int j = 0;
	int temp = 0;
	int res = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (A[i]>A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	i = 0;
	while (i < len)
	{
		if (A[i] == A[i +2])
		{
			if (i + 3 < len)
				i = i + 3;
		}
		else
		{
			res= A[i];
			break;
		}
	}
	return res;
}
	
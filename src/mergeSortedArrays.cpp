/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct dates{
	int date;
	int month;
	int year;

};
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	dates dts1[5];
	int temp = ALen + BLen;
	dates dts2[5];
	struct transaction result[10];
	for (i = 0; i < ALen; i++)
	{
		dts1[i].date = (((A[i].date[0] * 10) - '0') + ((A[i].date[1] * 1) - '0'));
		dts1[i].month = (((A[i].date[3] * 10) - '0') + ((A[i].date[4] * 1) - '0'));
		dts1[i].year = (((A[i].date[6] * 1000) - '0') + ((A[i].date[7] * 100) - '0') + ((A[i].date[8] * 10) - '0') + ((A[i].date[9] * 1) - '0'));


	}
	for (i = 0; i < BLen; i++)
	{
		dts2[i].date = (((B[i].date[0] * 10) - '0') + ((B[i].date[1] * 1) - '0'));
		dts2[i].month = (((B[i].date[3] * 10) - '0') + ((B[i].date[4] * 1) - '0'));
		dts2[i].year = (((B[i].date[6] * 1000) - '0') + ((B[i].date[7] * 100) - '0') + ((B[i].date[8] * 10) - '0') + ((B[i].date[9] * 1) - '0'));


	}
	int k = 0;
	i = 0;
	j = 0;
	while (i < ALen && j < BLen)
	{
		//checking least value and storing it in result
		if (dts1[i].year < dts2[j].year)
		{
			result[k] = A[i];
			i++;
		
		}
		else if (dts1[i].year == dts2[j].year)
		{
			if (dts1[i].month < dts2[j].month)
			{
				result[k] = A[i];
				i++;
			}
			else if (dts1[i].month == dts2[j].month)
			{
				if (dts1[i].date <= dts2[j].date)
				{
					result[k] = A[i];
					i++;
				}
				else
				{
					result[k] = B[j];
					j++;
				}
			}
			else
			{
				result[k] = B[j];
				j++;
			}
		}
		else
		{
			result[k] = B[j];
			j++;
		}
		k++;
	}
	//if all first struct elements are inserted dump second struct elements
	if (i >= ALen)
	{
		while (j<BLen)
		{
			result[k] = B[j];
			j++; 
			k++;
		}
	}
	//if all second struct elements are inserted dump first struct elements
	if(j>=BLen)
	{
		while (i<ALen)
		{
			result[k]= A[i];
			i++;
			k++;
		}
	}
	
	return result;
}













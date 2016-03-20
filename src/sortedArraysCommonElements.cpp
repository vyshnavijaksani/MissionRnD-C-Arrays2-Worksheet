/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


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


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0;
	int j = 0;
	dates dts1[5];
	dates dts2[5];
	struct transaction *result = NULL;
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
	//check for same dates and returning transaction with same dates
	for (i = 0; i < ALen;i++)
	{
		
		while(j < BLen)
		{
			if (dts1[i].year == dts2[j].year&&dts1[i].month == dts2[j].month&&dts1[i].date == dts2[j].date)
			{
				result=(struct transaction*)malloc(sizeof(struct transaction));
				result= &A[i];
			}
			j++;
		}
	}
		
	return result;
}
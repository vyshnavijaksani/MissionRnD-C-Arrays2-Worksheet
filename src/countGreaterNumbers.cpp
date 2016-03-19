/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	dates dts[5];
	for (i = 0; i < len; i++)
	{
		dts[i].date = (((Arr[i].date[0] * 10) - '0') + ((Arr[i].date[1] * 1) - '0'));
		dts[i].month = (((Arr[i].date[3] * 10) - '0') + ((Arr[i].date[4] * 1) - '0'));
		dts[i].year = (((Arr[i].date[6] * 1000) - '0') + ((Arr[i].date[7] * 100) - '0') + ((Arr[i].date[8] * 10) - '0') + ((Arr[i].date[9] * 1) - '0'));


	}
	int chkday;
	int chkmonth;
	int chkyear;
	int count = 0;
	chkday = (((date[0] * 10) - '0') +(( date[1] * 1) - '0'));
	chkmonth = (((date[3] * 10) - '0') + ((date[4] * 1) - '0'));
	chkyear = (((date[6] * 1000) - '0') + ((date[7] * 100) - '0') + ((date[8] * 10) - '0') + ((date[9] * 1) -'0'));
	i = 0;
	while (i < len)
	{
		if (dts[i].year > chkyear)
		{
			count++;
		}
		else if (dts[i].year == chkyear)
		{
			if (dts[i].month > chkmonth)
			{
				count++;
			}
			else if (dts[i].month == chkmonth)
			{
				if (dts[i].date > chkday)
				{
					count++;
				}
			}
		}
		i++;
	}
	return count;
}

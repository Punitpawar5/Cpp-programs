#include <stdio.h>
int main()
{
	int a[100][4]; 
	int i, j, n, total = 0, index, temp;
	float avg_wt;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &a[i][1]);
		a[i][0] = i + 1;		}
	
	// Sorting process according to their Burst Time
	for (i = 0; i < n; i++)	{
		index = i;
		for (j = i + 1; j < n; j++)
			if (a[j][1] < a[index][1])
				index = j;
		temp = a[i][1];
		a[i][1] = a[index][1];
		a[index][1] = temp;
		temp = a[i][0];
		a[i][0] = a[index][0];
		a[index][0] = temp;	}
	a[0][2] = 0;
	
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		a[i][2] = 0;
		for (j = 0; j < i; j++)
			a[i][2] += a[j][1];
		total += a[i][2];		}
	avg_wt = (float)total / n;
	total = 0;
	printf(" Process	 	BurstTime	 	WaitingTime\n");
	for (i = 0; i < n; i++)	 {
		printf(" P%d	 %d	 %d	 %d\n", a[i][0],
			a[i][1], a[i][2];	}
	printf("Average Waiting Time= %f", avg_wt);
}


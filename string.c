#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
	int m, n, i, j;
	char t[100], p[100];
	printf("Enter text String:");
	scanf("%[^\n]%*c", t);
	printf("Enter String to search:");
	scanf("%[^\n]%*c", p);
	n = strlen(t);
	m = strlen(p);
	printf("The length of Text string is %d\n", n);
	printf("The length of the Searching String is %d\n", m);
	for(i = 0; i < n-m; i++)
	{
		j = 0;
		while(j < m && p[j] == t[i + j])
		{
			j++;
			if(j == m)
			{
				printf("String found at %d position\n", i+1);
				getch();
				return;
			}
		}
	}
	printf("String not found\n");
	getch();
}
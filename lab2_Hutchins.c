
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const char *FNAME = "lab2.txt";

int main()
{
	char *line;		
	unsigned long n; 

	unsigned int r;
	int ccount;		
	int pcount;		

	FILE *fp;		
	

	line = NULL;
	n = 0; 

	fp = fopen(FNAME, "r");	
	if (fp == NULL)
	{
		printf("File '%s' not found.\n", FNAME);

		fclose(fp);
		exit(1);	
	}
	
	int procid;
	procid = fork();

	if (procid == 0)
	{
		//child processing here

		int cPID = getpid();
		ccount = 0;

		while (r != EOF)
		{
			r = getline(&line, &n, fp);
			if (r == EOF)
				break;
			printf("(pid: %d): %s", cPID, line);
			ccount ++;	
		}

		fclose(fp);
		printf("\n --> CHILD ID = %d \n", cPID);
		printf(" --> Number of lines read by CHILD process: %d \n", ccount);

		exit(1);
	}
	

	
	else
	{
		// parent processing here

		int pPID = getpid();
		pcount = 0;


		while (r != EOF)
		{	
			r = getline(&line, &n, fp);
			if (r == EOF)
				break;

			printf("(pid: %d): %s", pPID, line);
			pcount ++;
		}

		fclose(fp);
		printf("\n --> PARENT ID = %d \n", pPID);				
		printf(" --> Number of lines read by PARENT process: %d \n", pcount);
		exit(1);
	}


	return 0;


}




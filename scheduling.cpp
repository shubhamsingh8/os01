#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
int main()
{

	int fd, arr[100], count, count2;
    char buf[20];
	printf("\nEnter your name:");
	char userName[20];
	scanf("%s", &userName);
	printf("\nWelcome %s", userName);
	printf("\nEnter 1 to Log In and any other to exit");
	int logIn;
	scanf("%d", &logIn);
	if(logIn == 1){
    	fd = open("Process.txt", O_CREAT | O_RDWR);
    	if(fd == NULL)
    	{
        	printf("\nThe process is exploited"); //If the file fails to open
        	exit(1);
    	}
    	write(fd, "23_12_3_4_3",11 );
    	close(fd);
    	fd = open("Process.txt",O_RDONLY);
    	if(fd == NULL)
    	{
    	    printf("\nThe process is exploited"); //If the file fails to open
    	}
    	read(fd, buf, 18); //Reading the values into buffer character array
    	printf("\nThe buf :%s ", buf);
    	int burstTime[10];
    	int i, n, j, tat = 0, wTime = 0, temp;
    	int _atat=0, _awt=0;
    	float atat=0, awt=0;
    	char *p;
    	p = strtok(buf, "_"); //extracting the particular piece of text just like split function
    	count=0;
    	while(p != NULL && i<5)
    	{
    	    burstTime[i]=atoi(p); //Converting the character to integer value
        	p = strtok(NULL,"_");
    	    count++;
    	}
    	close(fd);
    	for(i=0;i<5;i++) // sorting the values according to burst time of the resp processes
    	{
    	    for(j=0;j<5;j++)
    	    {
    	        if(burstTime[j] > burstTime[i])
    	        {
    	            temp = burstTime[j];
        	        burstTime[j] = burstTime[i];
        	        burstTime[i] = temp;
        	    }
        	}
    	}	
    	printf("\nPid\t\t\t Bt\t\t\t Wt\t\t\t tAT\t\t\t");
    	for(i=0;i<5;i++) //executing and calculating the values of waiting time and turn around time
    	{
    	    tat = burstTime[i] + wTime;
    	    printf("\n%d\t\t\t %d\t\t\t %d\t\t\t %d\t\t\t ", i+1,burstTime[i], wTime, tat);
    	    _atat = _atat + tat;
    	    _awt += wTime;
    	    wTime = wTime + burstTime[i];
    	}
    	awt = (float)_awt/n;
    	atat = (float)_atat/n;
    	printf("\nThe average waiting time for the system is %f:",awt);
    	printf("\nThe average turn around time for the system is %f:", atat);
		}
		else
		{
		
			printf("\nThanks %s", userName);
		}
	time_t t;
	time(&t);
	printf("\n\n\t\t\tYou have logged into the system is %s", ctime(&t));
}


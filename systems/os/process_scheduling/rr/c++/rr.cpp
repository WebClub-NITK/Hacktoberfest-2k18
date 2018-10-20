#include <iostream>
#include <time.h>	// time()
#include <stdlib.h> // srand(), rand()
#include <vector>	// std::vector, vector.push_back()
#include <cstdio> // printf()

int main() 
{
	
	int quantum = 2;
	
	int n = 20; // number of processes

	int processes[n][2] = {};

	int wt[n] = {}; // waiting time for each process

	int tt[n] = {}; // turn around time for each process

	int st[n] = {}; // schedule time for each process

	int bt[n] = {}; // initial burst time for each process

	int cs = 0; // total number of context switches

	int t = 0; // total time

	std::vector<int> order; // the order in which the processes were scheduled by their index

	srand(time(NULL));

	// initializing processes with random values and printing them
	for(int i = 0; i < n; i++) 
	{
		processes[i][0] = rand() % 10; // burst time
		processes[i][1] = rand() % 50; // arrival time
	}
	
	// sorting processes by arrival time using bubble sort
	for(int i = 0; i < n; i++) 
	{
		for(int k = 0; k < n; k++) 
		{
			if(processes[k][1] > processes[k + 1][1]) 
			{
				int temp = processes[k + 1][1];
				processes[k + 1][1] = processes[k][1];
				processes[k][1] = temp;
			}
		}
	}

	for(int i = 0; i < n; i++) bt[i] = processes[i][0];

	// printing processes table
	printf("Process_index	arrival_time	burst_time\n");
	for(int i = 0; i < n; i++) 
	{
		printf("%d				%d 				%d\n", i, processes[i][1], processes[i][0]);
	}

	bool done = false;

	// traversing all the processes until they are done
	while(!done) 
	{
		done = true;

		// traversing processes one by one
		for(int i = 0; i < n; i++) 
		{

			st[i] = t;

			if(processes[i][0] > quantum) 
			{
				 // there are processes pending
				done = false;

				// decreasing burst time of current process
				processes[i][0] -= quantum;

				st[i] += quantum;
				t += quantum;
				cs++;

				order.push_back(i);

			} else {
				t += processes[i][0];
				st[i] += processes[i][0];

				// turn-around time is completion_time - arrival_time
				tt[i] = t - processes[i][1];

				// waiting time is turn_around_time - initial_burst_time
				wt[i] = t - bt[i];

				// last cycle of process
				processes[i][0] = 0;
			}
		}
	}

	printf("\n\n-----=====\tRESULTS\t=====-----\n\n");

	printf("Total number of context switches: %d\n", cs);
	printf("Total time: %d\n", t);

	// printing the order in which processes were scheduled

	printf("Process order: \n");

	for(int i = 0; i < order.size(); i++) 
	{
		printf(" --> Process %d", order.at(i));
	}

	printf("\n\n");

	printf("Process_index	waiting_time	turn_around_time	schedule_time\n");

	for(int i = 0; i < n; i++) 
	{
		printf("%d				%d				%d					%d\n", i, wt[i], tt[i], st[i]);
	}

	return 0;
}
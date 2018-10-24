#include <iostream>
#include <time.h>	// time()
#include <stdlib.h> // srand(), rand()
#include <vector>	// std::vector, vector.push_back()
#include <cstdio> // printf()
#include <string> // std::string, std::to_string()

int main() 
{
	
	int quantum = 2;
	
	int n = 20; // number of processes

	int processes[n][2] = {};

	int queque[n] = {}; // processes that are in the ready queque

	int wt[n] = {}; // waiting time for each process

	int tt[n] = {}; // turn around time for each process

	int bt[n] = {}; // initial burst time for each process

	std::string st[n] = {""}; // schedule times for each process

	int cs = 0; // total number of context switches

	int t = 0; // total time

	std::vector<int> order; // the order in which the processes were scheduled by their index

	srand(time(NULL));

	// initializing processes with random values
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

    // storing initial burst time values for processes in bt
	for(int i = 0; i < n; i++) bt[i] = processes[i][0];

	// printing processes table
	std::cout<<"ProcessNo	arrival_time	burst_time"<<std::endl;
	for(int i = 0; i < n; i++) 
	{
		std::cout<<i<<"		"<<processes[i][1]<<"		"<<processes[i][0]<<std::endl;
	}

	bool done = false;

	// traversing all the processes until they are done
	while(!done) 
	{
		done = true;

		// traversing all processes one by one
		for(int k = 0; k < n; k++) 
		{	
			if(processes[k][1] <= t && processes[k][0] != -1) {
				queque[k] = true;
			}
		}

			// traversing processes in the ready queque
			for(int i = 0; i < n; i++)
			{
				// checking if the current process is in the ready queque
				if(queque[i])
				{
					if(processes[i][0] >= quantum) 
					{

						t += quantum;

						 // there are processes pending
						done = false;

						// decreasing burst time of current process
						processes[i][0] -= quantum;

						// updating schedule time for this process
						st[i] += std::to_string(t) + " ";

						// updating the number of context switches
						cs++;

						// adding this process to the order of processes 
						order.push_back(i);

					} else if(processes[i][0] > -1){

						done = false;

						t += processes[i][0];

						st[i].append(std::to_string(t) + " ");

						// turn-around time is completion_time - arrival_time
						tt[i] = t - processes[i][1];

						// waiting time is turn_around_time - initial_burst_time
						wt[i] = t - bt[i];

						order.push_back(i);

						// last cycle of process
						processes[i][0] = -1;
					} else {
						//done = false; // there are still processes pending

						// since no processes have arrived at this point
						// one CPU cycle has passed
						t++;
					}
				}
			}
		}

	std::cout<<"Total number of context switches: "<<cs<<std::endl;
	
	std::cout<<"Total time: "<<t<<std::endl;

	// printing the order in which processes were scheduled
	std::cout<<"Process order: ";

	for(int i = 0; i < order.size(); i++) 
	{
		std::cout<<" ->"<<order.at(i)<<" ";
	}

	std::cout<<std::endl<<std::endl;

	std::cout<<"ProcessNo	waiting_time	turn_around_time	schedule_times"<<std::endl;

	for(int i = 0; i < n; i++) 
	{
		std::cout<<i<<"		"<<wt[i]<<"		"<<tt[i]<<"			"<<st[i]<<std::endl;

	}

	return 0;
}

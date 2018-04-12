#include<stdio.h>
#include<conio.h>

struct process{
	int id;
	int arrivalTime;
	int burstTime;
	int completed;
}p[10];

void main(){
	int num,i,j,time=0,pid;
	int readyQueue[10],finalQueue[10],min=1000,minpid;
	
	printf("Enter number of processes... (less than or equal to 10)\n");
	scanf("%d",&num);
	
	for(i=0;i<10;i++){
		readyQueue[i]=-1;
	}
	
	printf("\nEnter details of each process in increasing arrival time order...\n\n");
	for(i=0;i<num;i++){
		p[i].id = i;
		printf("\nProcess P%d",i+1);
		printf("\n	Enter arrival time :");
		scanf("%d",&p[i].arrivalTime);
		printf("	Enter burst time :");
		scanf("%d",&p[i].burstTime);
		p[i].completed = 0;
	}
	
	printf("\n\nFirst iteration...");
	j=0;
	for(i=0;i<num;i++){
		if(p[i].arrivalTime<=time && p[i].completed==0){
			p[i].burstTime -=3;
			time+=3;
			if(p[i].burstTime<=0){
				p[i].completed = 1;
				readyQueue[j]=-1;
			}
			if(p[i].completed == 0){
				j++;
				readyQueue[j]=p[i].id;
			}
		}
		j++;
	}
	

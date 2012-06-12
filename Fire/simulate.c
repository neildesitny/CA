/*
	 a function to simulate the forest fire model process:

 	 		initialize the map -> update the map -> plot
 														 \------------------/
																		loop
 */

#include "fire.h"

void simulate(dimension dim, probabilities prob){	

	char 	answer;
	int		count =0; // a counter for showing time steps

	int** map =(int**) malloc(dim.width*sizeof(int*)); // map of forest
	int** new_map = (int**)malloc(dim.width*sizeof(int*)); 

	num_tracker tracker;

	tracker.num_growing_tree = 0;
	tracker.num_burning_tree = 0;
	tracker.num_total_tree = 0;

	FILE* fp = fopen("data","w");									//file for storing forest data
	FILE* pipe = popen("gnuplot -persist","w");		//gnuplot for simulation
	FILE* pipe_1 = popen("gnuplot -persist","w"); //gnuplot for plotting statistics

	if(!fp){
		printf("errors happened during opening file data\n");
	}

	if(!pipe||!pipe_1){
		printf("errors happened during opening gnuplot\n");
		exit(1);
	}
	
	for(int i=0;i<dim.width;i++){
		map[i] = (int*)malloc(dim.height*sizeof(int));
		new_map[i] =(int*)malloc(dim.height*sizeof(int));
	}

	double ratio = prob.prob_lightning/prob.prob_to_tree;

	//initialize the map  
	init_map(map, new_map, dim, prob.prob_init_tree,&tracker);

	//if prob_lightning = 0, then set a fire in the centre of the map
	//To simulate the first situation 
	if(prob.prob_lightning == 0.0){

		for(int i=0;i<dim.width*0.03;i++){
			for(int j=0;j<dim.width*0.03;j++){
				map[dim.width/2+i][dim.height/2+j] = burning;
				tracker.num_total_tree -= 1;
				tracker.num_burning_tree += 1;
			}
		}

		// load configurations for simulating percolation
		fprintf(pipe,"load 'set_2.gp'\n");
	}else{
		fprintf(pipe,"load 'set_1.gp'\n");
	}
	
	// load configurations for ploting forest statistics
	fprintf(pipe_1,"load 'set.gp'\n");
	
	fprintf(fp, "#Count\t#Growing\t#Fire\t#Total Trees\n");

	//show the initial state of the map
	plot(fp,pipe,pipe_1,map, dim, count,ratio,tracker);

	printf("do you want to simulate right now?(y/n)");
	scanf("%c",&answer);

	if(answer == 'y'){
		//simulation display starts here
		while(true){

			count++;

			tracker.num_growing_tree = 0;
			tracker.num_burning_tree = 0;
			tracker.num_total_tree = 0;

			//update the map
			update_map(map, new_map, dim, prob.prob_to_tree, prob.prob_lightning,&tracker);

			//visualize the process by calling gnuplot
			plot(fp,pipe,pipe_1,map, dim, count,ratio,tracker);

			//uncomment to control the simulation speed 
			//usleep(1000000);
		}
	}else{
		fclose(fp);
		fclose(pipe_1);
		fclose(pipe);

		exit(0);
	}
}

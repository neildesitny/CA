/*
  a function to simulate the forest fire model process.
  this function invokes functions like init_map(), update_map() and prob().
*/
#include "fire.h"

void simulate(int width, int height, double probability, double prob_to_tree, double prob_lightning){
	
	int** map =(int**) malloc(width*sizeof(int*));
	int** new_map = (int**)malloc(width*sizeof(int*));
	int		count =0; // a counter for show time steps
	int 	num_growing_tree = 0; // track the number of growing trees(one timestep)
	int 	num_burnt_tree = 0; // track the number of burnt trees(one timestep)
	char answer;

	FILE* fp = fopen("data","w");
	FILE* pipe = popen("gnuplot -persist","w");	
	FILE* pipe1 = popen("gnuplot -persist","w");

	if(!fp){
		printf("errors happened during opening file data\n");
	}
	if(!pipe){
		printf("errors happened during opening gnuplot\n");
		exit(1);
	}
	
	// load configuration for gnuplot
	fprintf(pipe1,"set xlabel 'time step'\n set ylabel 'number'\n set autoscale\n");
	fprintf(pipe, "load 'set.gp'\n");
	
	for(int i=0;i<width;i++){
		map[i] = (int*)malloc(height*sizeof(int));
		new_map[i] =(int*)malloc(height*sizeof(int));
	}
		
	double ratio = prob_lightning/prob_to_tree;

	//initialize tha map before simulation
	init_map(map, new_map, width, height, probability);
		
	//if prob_lightning = 0, then set a fire in the centre of the map
	//To simulate the first situation
	if(prob_lightning == 0.0){
		for(int i=0;i<width*0.03;i++){
			for(int j=0;j<width*0.03;j++){
				map[width/2+i][height/2+j] = burning;
			}
		}
	}

	//show the initial state of the map
	plot(fp,pipe,pipe1,map, width, height, &count,ratio,num_growing_tree,num_burnt_tree);

	printf("do you want to simulate right now?(y/n)");
	scanf("%c",&answer);
	
	if(answer == 'y'){
		//simulation display starts here
		while(true){
			count ++;	

			//update the map
			update_map(map, new_map, width, height, prob_to_tree, prob_lightning,&num_growing_tree, &num_burnt_tree);

			//visualize the process by calling gnuplot
			plot(fp,pipe,pipe1,map, width, height, &count,ratio,num_growing_tree,num_burnt_tree);

			num_growing_tree = 0;
			num_burnt_tree = 0;

			//a function to control the simulation speed 
			//usleep(100000);
		}
	}
	else{
		exit(0);
	}
}

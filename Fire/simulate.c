/*
  a function to simulate the forest fire model process.
  this function invokes functions like init_map(), update_map() and prob().
*/
#include "fire.h"

void simulate(int width, int height, double probability, double prob_to_tree, double prob_lightning){
	// a map with width*height sites
	int** map =(int**) malloc(width*sizeof(int*));
	int** new_map = (int**)malloc(width*sizeof(int*));

	FILE* pipe = popen("gnuplot -persist","w");	
	
	fprintf(pipe, "load 'set.gp'\n");
	
	for(int i=0;i<width;i++){
		map[i] = (int*)malloc(height*sizeof(int));
		new_map[i] =(int*)malloc(height*sizeof(int));
	}
		
	//initialize tha map before simulation
	init_map(map, new_map, width, height, probability);
	
	//if prob_lightning = 0, then set a fire int the centre 
	//of the map
	if(prob_lightning == 0.0){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				map[width/2+i][height/2+j] = burning;
			}
		}
	}
	
	//simulation display starts here
	while(true){
		
		//visualize the process by calling gnuplot
		plot(pipe,map, width, height);
		
		//update the map
		update_map(map, new_map, width, height, prob_to_tree, prob_lightning);
		
		//a function to control the simulation speed by modifing the parameter
		usleep(100000);
	}
}

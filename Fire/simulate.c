/*
  a function to simulate the forest fire model process.
  this function invokes functions like init_map(), update_map() and prob().
*/
#include "fire.h"

//void simulate(int width, int height, double probability, double prob_to_tree, double prob_lightning){
void simulate(dimension dim, probabilities prob){	
	int** map =(int**) malloc(dim.width*sizeof(int*));
	int** new_map = (int**)malloc(dim.width*sizeof(int*));
	int 	num_growing_tree = 0; // track the number of growing trees(one timestep)
	int 	num_total_tree = 0;
	int 	num_burnt_tree = 0; // track the number of burnt trees(one timestep)
	char answer;
	int		count =0; // a counter for show time steps

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
	
	for(int i=0;i<dim.width;i++){
		map[i] = (int*)malloc(dim.height*sizeof(int));
		new_map[i] =(int*)malloc(dim.height*sizeof(int));
	}
		
	double ratio = prob.prob_lightning/prob.prob_to_tree;

	//initialize tha map before simulation
	init_map(map, new_map, dim, prob.prob_init_tree,&num_total_tree);
		
	//if prob_lightning = 0, then set a fire in the centre of the map
	//To simulate the first situation
	if(prob.prob_lightning == 0.0){
		for(int i=0;i<dim.width*0.03;i++){
			for(int j=0;j<dim.width*0.03;j++){
				map[dim.width/2+i][dim.height/2+j] = burning;
				num_total_tree --;
			}
		}
	}

	//show the initial state of the map
	plot(fp,pipe,pipe1,map, dim.width, dim.height,&count,ratio,num_growing_tree,num_burnt_tree,num_total_tree);

	printf("do you want to simulate right now?(y/n)");
	scanf("%c",&answer);
	
	if(answer == 'y'){
		//simulation display starts here
		while(true){

			count++;
			//update the map
//			update_map(map, new_map, width, height, prob_to_tree, prob_lightning,&num_growing_tree, &num_burnt_tree);
			update_map(map, new_map, dim, prob.prob_to_tree, prob.prob_lightning,&num_growing_tree, &num_burnt_tree);
			//visualize the process by calling gnuplot
			plot(fp,pipe,pipe1,map, dim.width, dim.height,&count, ratio,num_growing_tree,num_burnt_tree,num_total_tree);

			num_growing_tree = 0;
			num_burnt_tree = 0;

			//uncomment to control the simulation speed 
//			usleep(1000000);
		}
	}
	else{
		exit(0);
	}
}

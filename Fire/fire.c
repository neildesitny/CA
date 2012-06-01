#include "fire.h"

int main(int argc, char** argv){
	int 		width, height;
	double	probability, prob_to_tree, prob_lightning;

	// check whether all requred data are entered
	if(argc!=6){
		printf("usage of this program\n");
		printf("./fire [width] [height] [tree_probability] [prob_to_tree] [prob_lightning]\n");
		printf("\n");
		exit(1);
	} else{
		width = atoi(argv[1]);
		height = atoi(argv[2]);
		probability = atof(argv[3]);
		prob_to_tree = atof(argv[4]);
		prob_lightning = atof(argv[5]);		
	}

	//srand(time(NULL));

	// start to running the simulation
	simulate(width,height,probability,prob_to_tree,prob_lightning);
	
	return 0;
}

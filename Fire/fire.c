#include "fire.h"

int main(int argc, char** argv){
	//int 		width, height;
	//double	probability, prob_to_tree, prob_lightning;
	dimension	dim;
	probabilities	prob;
	
	// check whether all required data are entered
	if(argc!=6){
		printf("usage of this program\n");
		printf("./fire [width] [height] [tree_probability] [prob_to_tree] [prob_lightning]\n");
		printf("\n");
		exit(1);
	} else{
		dim.width = atoi(argv[1]);
		dim.height = atoi(argv[2]);
		prob.prob_init_tree= atof(argv[3]);
		prob.prob_to_tree = atof(argv[4]);
		prob.prob_lightning = atof(argv[5]);		
	}

	//srand(time(NULL));

	// start to running the simulation
//	simulate(width,height,probability,prob_to_tree,prob_lightning);
	simulate(dim,prob);
	return 0;
}

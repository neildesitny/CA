/*
 	update the state of each site with probability of prob_to_tree 
	and prob_lightning 

  prob_to_tree stands for the probability that an empty becomes tree 

  prob_lightning stands for the probability that a tree becomes burning 
	because of lightning
*/

#include "fire.h"

void update_map(int** map, int** new_map, dimension dim, double prob_to_tree, double prob_lightning, num_tracker* tracker){ 
	//check the state of each site after one time step
	for(int i=0;i<dim.width;i++){
		for(int j=0;j<dim.height;j++){
			switch(map[i][j]){
				case empty: 	
					if(prob(prob_to_tree)){
						new_map[i][j] = tree;
						tracker->num_growing_tree += 1;
					}
					break;

				case burning: 
					new_map[i][j] = empty;
					tracker->num_burning_tree += 1;
					break;

				default:
					tracker->num_total_tree += 1;

					//periodic boundary conditions and Von Neumann neighbourhood 
					if(map[i>0?i-1:dim.width-1][j] == burning||
							map[i<dim.width-1?i+1:0][j] == burning||
							map[i][j>0?j-1:dim.height-1] == burning||
							map[i][j<dim.height-1?j+1:0] == burning||
							prob(prob_lightning)){
						new_map[i][j] = burning;
					}
			}
		}
	}

	//update the map
	for(int i=0;i<dim.width;i++){
		for(int j=0;j<dim.height;j++){
			map[i][j] = new_map[i][j];
		}
	}
}


/*
 	update the state of each site with probability of p and f
   p stands for the probability that a tree becomes burning
   f stands for the probability that a tree becomes burning because of
   lightning
*/

#include "fire.h"

void update_map(int** map, int** new_map, int width,int height, double prob_to_tree, double prob_lightning,int* num_growing_tree, int* num_burnt_tree){
	
	//check the state of each site after one time step
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			switch(map[i][j]){
				case empty:	if(prob(prob_to_tree)){new_map[i][j] = tree;*num_growing_tree += 1;}break;
				case burning: new_map[i][j] = empty;*num_burnt_tree +=1; break;
				default:
					//use periodic boundary conditions and the neighbourhood is Von Neumann neighbourhood without central site
					if(map[i>0?i-1:width-1][j] == burning||
					map[i<width-1?i+1:0][j] == burning||
					map[i][j>0?j-1:height-1] == burning||
					map[i][j<height-1?j+1:0] == burning||
					prob(prob_lightning)){
						new_map[i][j] = burning;
					}
			}
		}
	}
	
	//update the map
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			map[i][j] = new_map[i][j];
		}
	}
}

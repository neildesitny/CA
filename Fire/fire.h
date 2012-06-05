#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
	 a structure to store width and height of the forest lattice
 */
typedef struct{
	int 	width;
	int		height;
}dimension;

/*
   a structure to store probabilities
 */
typedef struct{
	double  prob_init_tree; 
	double 	prob_to_tree;
	double  prob_lightning;
}probabilities;

/*
	 all the possible states of a site.
	 a site can be empty, occupied by a green tree or a burning tree.
	 ash is equal to empty, it is used to track the burnt site
 */
enum {empty = 0, tree = 1, burning = 2,ash = 3};

/*
	 a function to simulate probability, if successful, return true
 */
bool prob(double x);

/*
	 a function to initialize a map with width * height sites,
	 and certain probability of a site is occupied by a tree
 */
//void init_map(int** map, int** new_map, int width, int height, double probability,int* num_total_tree);
void init_map(int** map, int** new_map, dimension dim, double probability,int* num_total_tree);

/*
	 update the state of each site with the probability of prob_to_tree and 
	 prob_lightning, also track the number of growing trees and burnt trees 
	 in one time step
 */
//void update_map(int** map, int** new_map, int width, int height, double prob_to_tree, double prob_lightning,int* num_growing_tree, int* num_burnt_tree);
void update_map(int** map, int** new_map, dimension dim, double prob_to_tree, double prob_lightning, int* num_growing_tree, int* num_burnt_tree); 

/*
	 a function using gnuplot to visualize simulation data
 */
void plot(FILE* fp, FILE* pipe, FILE* pipe1, int** map, int width, int height, int *count, double ratio,int num_growing_tree,int num_burnt_tree,int num_total_tree);

/*
	 a function to simulate the forest fire model process.
	 this function invokes all the above functions
 */
void simulate(dimension dim,probabilities prob);

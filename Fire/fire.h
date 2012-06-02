#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
  all the possible states of a site.
  a site can be empty, occupied by a tree or burning.
*/
		enum {empty = 0, tree = 1, burning = 2};

/*
 	a function to simulate probability, if successful, return true, else false
*/
		bool prob(double x);

/*
 	a function to initialize a map with width * height sites,
  and certain probability of a site is occupied by a tree
*/
		void init_map(int** map, int** new_map, int width, int height, double probability);

/*
 	update the state of each site with probability of p and f.
  p stands for the probability that a tree becomes burning
  f stands for the probability that a tree becomes burning because of
  lightning
*/
		void update_map(int** map, int** new_map, int width, int height, double prob_to_tree, double prob_lightning,int* num_growing_tree, int* num_burnt_tree);

/*
	a function using gnuplot to visualize simulation data
*/
		void plot(FILE* fp, FILE* pipe, FILE* pipe1, int** map, int width, int height, int* count, double ratio,int num_growing_tree,int num_burnt_tree);

/*
 	a function to simulate the forest fire model process.
  this function invokes all the functions above.
*/
		void simulate(int width, int height, double probability, double prob_to_tree, double prob_lightning);

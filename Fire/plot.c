/*
 	a function to simulate the forest fire model process.
*/

#include "fire.h"

void plot(FILE* fp, FILE* pipe, FILE* pipe1, int** map, int width, int height,int *count,double ratio,int num_growing_tree, int num_burnt_tree,int num_total_tree){

	//track the number of growing and burnt trees to show the steady state
	fprintf(fp,"%d %lf %lf\n",*count, (double)num_growing_tree/(width*height),(double)num_burnt_tree/(width*height));

	fprintf(pipe1, "plot 'data' using 1:3 t 'burning tree' w l, 'data' using 1:2 t 'growing tree' w l\n");

	fflush(fp);
	fflush(pipe1);

	//visualization of the forest fire 
	fprintf(pipe, "plot '-' matrix title 'f/p = %lf Frame:%d' with image\n",ratio,*count);

	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			fprintf(pipe, "%d ",map[i][j]);
		}
		fprintf(pipe,"\n");
	}

	fprintf(pipe,"\ne\n");
	fflush(pipe);
}

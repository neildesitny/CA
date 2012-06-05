/*
	 a function to simulate the forest fire model process.
 */

#include "fire.h"

void plot(FILE* fp, FILE* pipe, FILE* pipe1, int** map, int width, int height,int count,double ratio, num_tracker* tracker){

	//track the number of growing and burnt trees to show the steady state
	fprintf(fp,"%d %lf %lf %lf %lf\n",count, 
			(double)tracker->num_growing_tree,
			(double)tracker->num_burning_tree,
			(double)tracker->num_total_tree,
			(double)tracker->num_total_fire);

	//	fprintf(pipe1, "plot 'data' using 1:($3/%d) t 'burning tree' w l, 'data' using 1:($2/%d) t 'growing tree' w l\n", width*height, width*height);

	fprintf(pipe1, "plot 'data' using 1:3 t 'burning trees' w l, 'data' using 1:2 t 'growing trees' w l\n");

	fflush(fp);
	fflush(pipe1);

	//visualization of the forest fire model
	fprintf(pipe, "plot '-' matrix title 'f/p = %lf Frame:%d' with image\n",ratio,count);

	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			fprintf(pipe, "%d ",map[i][j]);
		}
		fprintf(pipe,"\n");
	}

	fprintf(pipe,"\ne\n");
	fflush(pipe);
}

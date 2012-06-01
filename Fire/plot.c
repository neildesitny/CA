/*
 	a function to simulate the forest fire model process.
*/

#include "fire.h"

void plot(FILE* pipe, int** map, int width, int height,int* count,double ratio){
	//start to plot
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

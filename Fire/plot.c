/*
 	a function to simulate the forest fire model process.
  this function invokes all the functions above.
*/

#include "fire.h"

void plot(FILE* pipe, int** map, int width, int height,int* count){
	//start to plot
	fprintf(pipe, "plot '-' matrix title 'Frame:%d' with image\n",*count);
	
		for(int i=0;i<width;i++){
			for(int j=0;j<height;j++){
				fprintf(pipe, "%d ",map[i][j]);
			}
			fprintf(pipe,"\n");
		}
		
		fprintf(pipe,"\ne\n");
		fflush(pipe);
}

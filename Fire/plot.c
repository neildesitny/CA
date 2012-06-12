/*
	 a function to visualize the forest fire model process.
 */

#include "fire.h"

void plot(FILE* fp, FILE* pipe, FILE* pipe_1, int** map, dimension dim,int count,double ratio, num_tracker tracker){

	int		map_size = dim.width * dim.height;

	// track status of the forest 
	fprintf(fp," %d\t\t\t %.1lf \t\t\t %.1lf \t\t\t %.1lf\t\n",count, 
			(double)tracker.num_growing_tree,
			(double)tracker.num_burning_tree,
			(double)tracker.num_total_tree);

	fflush(fp);

	// track the density of tree, empty site and fire
	fprintf(pipe_1, "set multiplot layout 2,1\n \
									set title 'Density'\n \
									set ylabel 'density'\n \
									plot 'data' using 1:($3/%d) t 'burning tree' w l,\
					 						 'data' using 1:($4/%d) t 'tree' w l,\
					 					   'data' using 1:(1.0-($3+$4)/%d) t 'empty' w l\n", 
				map_size, map_size, map_size);
	
	// track the number of growing trees and burnt trees in steady state
	fprintf(pipe_1, "set title 'Population'\n \
									set ylabel 'number'\n \
									plot 'data' using 1:3 t 'burning trees' w l, \
											 'data' using 1:2 t 'growing trees' w l\n \
									unset multiplot\n");

	fflush(pipe_1);

	//visualization of the forest fire model
	fprintf(pipe, "plot '-' matrix title 'f/p = %lf Frame:%d' with image\n",
			ratio,count);

	for(int i=0;i<dim.width;i++){
		for(int j=0;j<dim.height;j++){
			fprintf(pipe, "%d ",map[i][j]);
		}
		fprintf(pipe,"\n");
	}

	fprintf(pipe,"\ne\n");
	fflush(pipe);
}

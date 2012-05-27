/*
 	a function to simulate probability, if successful, return true, else false
*/


#include "fire.h"

bool prob(double x){
	return rand()<RAND_MAX*x;
}

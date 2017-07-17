#include "Particles.h"
#include<stdlib.h>
#include<math.h>
using namespace std;
Particles::Particles()
{
	//x = (2.0 *rand())/RAND_MAX - 1;
	//y = (2.0 *rand()) / RAND_MAX -1 ;
	x = 0;
	y = 0;
	//speedX = 0.01*(((2.0*rand()) / RAND_MAX) - 1);
	//speedY = 0.01*(((2.0*rand()) / RAND_MAX) - 1);
	speed = (0.01*rand()) / RAND_MAX ;
		direction =(2.0* 3.14)* rand() / RAND_MAX ;
}


Particles::~Particles()
{
}

void Particles::update(){
	speedX = speed * cos(direction);
	speedY = speed * sin(direction); 
	
	x += speedX;
	y += speedY;
}

#include<iostream>
#include"SDL.h"
#include<iostream>
#include"Screen.h"
#include<math.h>
#include<stdlib.h>
#include"Swarm.h"
using namespace std;

int main(int argc,char *argv[]){
	Screen scrn;
	if (!scrn.Init()){
		cout << "Error initializing";
	}

	Swarm swarm(5000);
	while (true){
		//Update Particle
		//Draw Particles
		//Check for events
		swarm.update();
		Particles * particles = swarm.getParticles();
		for (int i = 0; i < 5000; i++){
			Particles temp = particles[i];

			int x = (temp.x+1) * Screen::SCREEN_WIDTH / 2;
			int y = (temp.y+1) * Screen::SCREEN_HEIGHT / 2;
			scrn.setPixel(x, y, 255,0,0);
		}

		if (scrn.processEvents() == false){
			break;
		}

		/*
		for (int i = 0; i < 400; i++){
			for (int j = 0; j < 400;j++){

				scrn.setPixel(i, j, 128, 0, 255);
			}
		}*/
		scrn.update();
		
		scrn.blur();
		//scrn.clear();
	}
	scrn.close();
	return EXIT_SUCCESS;
}
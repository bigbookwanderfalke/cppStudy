#include "SDL.h"

#define SDL_INIT_TYPES	(SDL_INIT_VIDEO /*| SDL_INIT_AUDIO*/)

void TrancateEvent(SDL_Event *e) {
	while(SDL_PollEvent(e)) {
		switch(e->type) {
			case SDL_VIDEOEXPOSE:
				break;

			case SDL_QUIT:
				exit(0);
				break;
		}
	}
}

int main() {
	SDL_Event event;

	if(SDL_Init(SDL_INIT_TYPES) == -1) {
		printf("error\n");
		return -1;
	}
	printf("SDL init success!\n");

	while(1) {
		TrancateEvent(&event);

		SDL_Delay(16);
	}

	SDL_Quit();
	return 0;
}

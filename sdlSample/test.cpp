/* 
 * 
 */

#include <iostream>
#include <iomanip>
#include "SDL.h"

int main()
{
	int e = 0;
	do {
		/* SDL.h */
		uint32_t	sdlInitFlag = (SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_CDROM | SDL_INIT_JOYSTICK);
//		uint32_t	sdlInitAll = SDL_INIT_EVERYTHING;

		/* SDL.h */
		if(SDL_Init(sdlInitFlag) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			e = 1;
			break;
		}

		/* SDL_video.h */
		int			srfWidth = 640;
		int			srfHeight = 480;
		int			srfBpp = 32;
		uint32_t	srfFlags = (SDL_SWSURFACE | SDL_DOUBLEBUF);
		SDL_Surface	*srf = SDL_SetVideoMode(srfWidth, srfHeight, srfBpp, srfFlags);
		if(srf == NULL) {
			std::cout << "SDL_SetVideoMode Error: " << SDL_GetError() << std::endl;
			e = 1;
			break;
		}

		/* SDL_video.h */
		const char	winTitle[] = "SDL Test";
		const char	*winIcon = NULL;
		SDL_WM_SetCaption(winTitle, winIcon);

		/* SDL_video.h */
		SDL_Rect	*srfDestRect = NULL;
		uint32_t	srfColor = SDL_MapRGB(srf->format, 0, 0, 0);

		int loopCount = 0;
		int exit = 0;
		do {
			/* SDL_events.h */
			SDL_Event evEvent;
			if(SDL_PollEvent(&evEvent)) {
				switch(evEvent.type) {
					case SDL_KEYDOWN:
						switch(evEvent.key.keysym.sym) {
							case SDLK_UP:
								srfColor = SDL_MapRGB(srf->format, 255, 0, 0);
								break;
							case SDLK_RIGHT:
								srfColor = SDL_MapRGB(srf->format, 0, 255, 0);
								break;
							case SDLK_LEFT:
								srfColor = SDL_MapRGB(srf->format, 0, 0, 255);
								break;
							case SDLK_DOWN:
								exit = 1;
								break;
							default:
								break;
						}
					default:
						break;
				}
			}
			if(exit == 1) {
				break;
			}

			/* SDL_video.h */
			int	fillRectResult = SDL_FillRect(srf, srfDestRect, srfColor);
			if(fillRectResult != 0) {
				std::cout << "SDL_FillRect Error: " << fillRectResult << ": " << SDL_GetError() << std::endl;
				e = 1;
				break;
			}

			/* SDL_video.h */
			SDL_Flip(srf);

			/* SDL_active.h */
/*
			uint8_t	appState = SDL_GetAppState();
			std::cout << "[" << std::dec << std::setw(5) << std::setfill('0') << loopCount << "] "
			   	<< pending << ":" << std::hex << appState << std::endl;
*/

			/* SDL_timer.h */
			uint32_t	delayTime = 1;	/* 1msec */
			SDL_Delay(delayTime);

			loopCount++;
		} while(1);
	} while(0);

	/* SDL.h */
	SDL_Quit();

	return e;
}


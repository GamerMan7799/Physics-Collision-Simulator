/**********************************************************************************************************************************************************************/
#include "screen.h"
/**********************************************************************************************************************************************************************/
//These are the paths to the images needed for the program
//They are relative to the exe
#define DEFINED_SKY_BMP_PATH_STR ".\\images\\sky.bmp"
#define DEFINED_BALL_BMP_PATH_STR ".\\images\\ball.bmp"
/**********************************************************************************************************************************************************************/
clsScreen::clsScreen() {
    //Basic constructor, defaults size to 680 w by 480 h
    width = 680;
    height = 480;

    blnWindow = false;
    blnRenderer = false;
    blnSky = false;
    blnBall = false;
    bln_SDL_started = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		bln_SDL_started = false;
		error();
		return;
	} else {
	    bln_SDL_started = true;
	    if (Global::blnDebugMode) {printf("SDL init successful\n");}
    }

	win = SDL_CreateWindow("Cannon Simulation",100,100,width, height, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
        printf("SDL Failed to create window.\n");
        cleanup();
        error();
		bln_SDL_started = false;
		return;
	} else {
	    blnWindow = true;
	    if (Global::blnDebugMode) {printf("Window creation successful\n");}
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
        printf("SDL Failed to create renderer.\n");
        cleanup();
        error();
        bln_SDL_started = false;
        return;
	} else {
	    blnRenderer = true;
	    if (Global::blnDebugMode) {printf("Renderer creation successful\n");}
    }

	sky = loadIMG(DEFINED_SKY_BMP_PATH_STR);
    if (bln_SDL_started == false) {return;}
    else {
        blnSky = true;
        if (Global::blnDebugMode) {printf("Sky loading successful\n");}
    }

    ball = loadIMG(DEFINED_BALL_BMP_PATH_STR);
    if (bln_SDL_started == false) {return;}
    else {
        blnBall = true;
        if (Global::blnDebugMode) {printf("Ball loading successful\n");}
    }
}
/**********************************************************************************************************************************************************************/
clsScreen::~clsScreen() {
    cleanup();
    SDL_Quit();
    if (Global::blnDebugMode) {printf("SDL quit\n");}
}
/**********************************************************************************************************************************************************************/
void clsScreen::update(void) {
    //static uint uintUpdateCounter;
    //function for just updating the screen, nothing else
    //on its own in case I want to just update the screen at some point
    SDL_RenderPresent(ren);
    //uintUpdateCounter++;
    //printf("%d\n",uintUpdateCounter);
}
/**********************************************************************************************************************************************************************/
void clsScreen::updateBall(LOC newplace) {
    //Make sure the values aren't going off screen
    //not sure if that would cause an error, but I feel like
    //dealing with it if it does.
    if (newplace.x > width) {newplace.x = width;}
    if (newplace.y > height) {newplace.y = 0;}
    //Clear renderer
    SDL_RenderClear(ren);
    //Copy sky
    SDL_RenderCopy(ren,sky,NULL,NULL);

    //Because the top left is 0,0 I have to change the y value to match this
    newplace.y = height - newplace.y;

    SDL_Rect dst;
    dst.x = newplace.x;
    dst.y = newplace.y;
    //Query ball texture to get its width and height
    SDL_QueryTexture(ball,NULL,NULL, &dst.w, &dst.h);
    //Place the ball
    SDL_RenderCopy(ren,ball,NULL,&dst);

    update(); //update screen
}
/**********************************************************************************************************************************************************************/
void clsScreen::cleanup(void) {
    if (blnBall) {
        SDL_DestroyTexture(ball);
        blnBall = false;
        printf("Ball texture destroyed\n");
    }
	if (blnSky) {
        SDL_DestroyTexture(sky);
        blnSky = false;
        printf("Sky texture destroyed\n");
    }
	if (blnRenderer) {
        SDL_DestroyRenderer(ren);
        blnRenderer = false;
        printf("Renderer destroyed\n");
    }
	if (blnWindow) {
        SDL_DestroyWindow(win);
        blnWindow = false;
        printf("Window destroyed\n");
    }
}
/**********************************************************************************************************************************************************************/
void clsScreen::error(void) {
    printf("SDL error: %s\n", SDL_GetError());
	getchar();
}
/**********************************************************************************************************************************************************************/
SDL_Texture* clsScreen::loadIMG(std::string filename) {
    SDL_Surface* temp = SDL_LoadBMP(filename.c_str());

	if (temp == nullptr) {
        printf("Failed to load img.\n");
        cleanup();
        error();
        bln_SDL_started = false;
        return nullptr;
	} else {
	    if (Global::blnDebugMode) {printf("img to surface successful\n");}
    }

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren,temp);
	SDL_FreeSurface(temp);
	if (tex == nullptr) {
        printf("Failed to create texture.\n");
        cleanup();
        error();
        bln_SDL_started = false;
	} else {
	    if (Global::blnDebugMode) {printf("Surface to texture successful\n");}
    }

	return tex;
}
/**********************************************************************************************************************************************************************/
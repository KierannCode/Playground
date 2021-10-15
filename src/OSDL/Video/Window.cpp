/*
 * Window.cpp
 *
 *  Created on: 12 sept. 2021
 *      Author: Kierann
 */

#include "Window.hpp"

#include "Surface.hpp"
#include "Color.hpp"

#include "../Resilience/Exception/SDLException.hpp"
#include "../Resilience/Log.hpp"

#include <SDL_video.h>
#include <SDL_mouse.h>

#include <SDL_render.h>

OSDL::Window::Window(OSDL::Size width, OSDL::Size height, const char *name) {
	window = SDL_CreateWindow(name,
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
		throw OSDL::SDLException();
	}
}

OSDL::Size OSDL::Window::getWidth() const {
	SDL_Surface *windowSurface = SDL_GetWindowSurface(window);
	if (windowSurface == nullptr) {
		throw OSDL::SDLException();
	}
	return windowSurface->w;
}
OSDL::Size OSDL::Window::getHeight() const {
	SDL_Surface *windowSurface = SDL_GetWindowSurface(window);
	if (windowSurface == nullptr) {
		throw OSDL::SDLException();
	}
	return windowSurface->h;
}

void OSDL::Window::updateSurface(OSDL::Surface *surface) {

	SDL_Rect r;
	r.x = 200;
	r.y = 100;
	r.w = 200;
	r.h = 100;

	SDL_Surface *windowSurface = SDL_GetWindowSurface(window);
	if (windowSurface == nullptr) {
		throw OSDL::SDLException();
	}
	if (SDL_BlitSurface(surface->surface, nullptr, windowSurface, nullptr)
			== -1) {
		throw OSDL::SDLException();
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &r);
	//SDL_RenderDrawPoint(renderer, 400, 400);
	//SDL_RenderPresent(renderer);
	//SDL_DestroyRenderer(renderer);
	if (SDL_UpdateWindowSurface(window) == -1) {
		OSDL::Log::startWarning() << OSDL::SDLException().what() << OSDL::Log::end;
	}
}

OSDL::Window::~Window() {
	SDL_DestroyWindow(window);
}

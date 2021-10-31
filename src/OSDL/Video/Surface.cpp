/*
 * Surface.cpp
 *
 *  Created on: 15 sept. 2021
 *      Author: Kierann
 */

#include "Surface.hpp"

#include "Color.hpp"

#include "../Math/Math.hpp"

#include "../Resilience/Exception/SDLException.hpp"
#include "../Resilience/Log.hpp"

#include <SDL_video.h>

OSDL::Surface::Surface(OSDL::Size width, OSDL::Size height) {
	surface = SDL_CreateRGBSurface(0, width, height, 32, OSDL::Color::RMask,
			OSDL::Color::GMask, OSDL::Color::BMask, OSDL::Color::AMask);
}
OSDL::Surface::Surface(OSDL::Size width, OSDL::Size height,
		const OSDL::Color &color) {
	surface = SDL_CreateRGBSurface(0, width, height, 32, OSDL::Color::RMask,
			OSDL::Color::GMask, OSDL::Color::BMask, OSDL::Color::AMask);
	SDL_FillRect(surface, nullptr, color.color);
}
OSDL::Surface::Surface(const std::string &imageFilename) {
	SDL_Surface *image = SDL_LoadBMP(imageFilename.c_str());
	if (image == nullptr) {
		throw OSDL::SDLException("Verify that the requested ressource is accessible from the executable location");
	}
	surface = SDL_CreateRGBSurface(0, image->w, image->h, 32,
			OSDL::Color::RMask, OSDL::Color::GMask, OSDL::Color::BMask,
			OSDL::Color::AMask);
	SDL_BlitSurface(image, nullptr, surface, nullptr);
	SDL_FreeSurface(image);
}

void OSDL::Surface::setAlphaKey(OSDL::Color key) {
	SDL_SetColorKey(surface, SDL_TRUE, key.color);
}

OSDL::Size OSDL::Surface::getWidth() const {
	return surface->w;
}
OSDL::Size OSDL::Surface::getHeight() const {
	return surface->h;
}

void OSDL::Surface::blit(OSDL::Surface *surface, int x, int y) const {
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_BlitSurface(this->surface, nullptr, surface->surface, &pos);
}

void OSDL::Surface::fill(const OSDL::Color &color) {
	SDL_FillRect(surface, nullptr, color.color);
}

void OSDL::Surface::fillRect(int x, int y, int width, int height,
		const OSDL::Color &color) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	SDL_FillRect(surface, &rect, color.color);
}

void OSDL::Surface::fillDisk(float cx, float cy, float radius,
		const OSDL::Color &color) {
	int minY = Math::max(0, Math::floor(cy - radius));
	int maxY = Math::min(surface->h - 1, Math::ceil(cy + radius));
	int minX = Math::max(0, Math::floor(cx - radius));
	int maxX = Math::min(surface->w - 1, Math::ceil(cx + radius));
	for (int j = minY; j <= maxY; ++j) {
		for (int i = minX; i < maxX; ++i) {
			if ((i - cx) * (i - cx) + (j - cy) * (j - cy) < radius * radius) {
				((Uint32*) surface->pixels)[i + j * surface->w] = color.color;
			}
		}
	}
}

OSDL::Surface::~Surface() {
	SDL_FreeSurface(surface);
}

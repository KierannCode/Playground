/*
 * Window.hpp
 *
 *  Created on: 11 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_VIDEO_WINDOW_HPP_
#define SRC_OSDL_VIDEO_WINDOW_HPP_

#include "../Types.hpp"

struct SDL_Window;
struct SDL_Surface;

namespace OSDL {
class Surface;

class Window {
public:
	Window(OSDL::Size width, OSDL::Size height, const char *name);

	OSDL::Size getWidth() const;
	OSDL::Size getHeight() const;

	void updateSurface(OSDL::Surface *surface);

	~Window();
private:
	SDL_Window *window;
};
}

#endif /* SRC_OSDL_VIDEO_WINDOW_HPP_ */

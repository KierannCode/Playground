/*
 * Surface.hpp
 *
 *  Created on: 11 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_VIDEO_SURFACE_HPP_
#define SRC_OSDL_VIDEO_SURFACE_HPP_

#include "../Types.hpp"

#include <string>

struct SDL_Surface;

namespace OSDL {
class Color;
class Window;

class Surface {
public:
	Surface(OSDL::Size width, OSDL::Size height);
	Surface(OSDL::Size width, OSDL::Size height, const OSDL::Color &color);
	Surface(const std::string &imageFilename);

	void setAlphaKey(OSDL::Color key);

	OSDL::Size getWidth() const;
	OSDL::Size getHeight() const;

	void blit(OSDL::Surface *surface, int x, int y) const;

	void fill(const OSDL::Color &color);
	void fillRect(int x, int y, int width, int height,
			const OSDL::Color &color);
	void fillDisk(float cx, float cy, float radius, const OSDL::Color &color);

	~Surface();
private:
	SDL_Surface *surface;

	friend class OSDL::Window;
};
}

#endif /* SRC_OSDL_VIDEO_SURFACE_HPP_ */

/*
 * Renderer.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_VIDEO_RENDERER_HPP_
#define SRC_VIDEO_RENDERER_HPP_

#include "../OSDL/Thread/ThreadLoop.hpp"

class Core;
class SoftwareRenderer;

namespace OSDL {
class Window;
class Surface;
class AtomicBoolean;
class Mutex;
}

class Renderer: public OSDL::ThreadLoop {
public:
	Renderer(OSDL::Window &window);

	void setSoftwareRenderer(SoftwareRenderer *softwareRenderer);

	void requestSurfaceResizing();

	bool isReady() const;
	void prepareRendering();

	Renderer::~Renderer();
private:
	OSDL::Window *window;

	OSDL::Mutex *softwareMutex;

	SoftwareRenderer *softwareRenderer;

	OSDL::Surface *renderingSurface;
	OSDL::AtomicBoolean *surfaceSizeChanged;

	OSDL::AtomicBoolean *renderingOver;

	void loopCode();
};

#endif /* SRC_VIDEO_RENDERER_HPP_ */

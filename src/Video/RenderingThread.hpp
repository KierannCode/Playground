/*
 * RenderingThread.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_RENDERINGTHREAD
#define PLAYGROUND_RENDERINGTHREAD

#include "../OSDL/Thread/ThreadLoop.hpp"

class Core;
class SoftwareRenderer;

namespace OSDL {
class Window;
class Surface;
class AtomicBoolean;
class Mutex;
}

class RenderingThread: public OSDL::ThreadLoop {
public:
	RenderingThread(OSDL::Window &window);

	void setSoftwareRenderer(SoftwareRenderer *softwareRenderer);

	void requestSurfaceResizing();

	bool isReady() const;
	void prepareRendering();

	RenderingThread::~RenderingThread();
private:
	OSDL::Window *window;

	OSDL::Mutex *softwareMutex;

	SoftwareRenderer *softwareRenderer;

	OSDL::Surface *renderingSurface;
	OSDL::AtomicBoolean *surfaceSizeChanged;

	OSDL::AtomicBoolean *renderingOver;

	void loopCode();
};

#endif /* PLAYGROUND_RENDERINGTHREAD */

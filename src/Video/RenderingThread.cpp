/*
 * RenderingThread.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "../Software/SoftwareRenderer.hpp"

#include "../OSDL/Data/Atomic/AtomicBoolean.hpp"

#include "../OSDL/Resilience/Log.hpp"

#include "../OSDL/Thread/Mutex.hpp"

#include "../OSDL/Video/Window.hpp"
#include "../OSDL/Video/Surface.hpp"
#include "RenderingThread.hpp"

RenderingThread::RenderingThread(OSDL::Window &window) {
	this->window = &window;

	softwareRenderer = nullptr;

	softwareMutex = new OSDL::Mutex;

	renderingSurface = new OSDL::Surface(window.getWidth(), window.getHeight());
	surfaceSizeChanged = new OSDL::AtomicBoolean(false);

	renderingOver = new OSDL::AtomicBoolean(true);
}

void RenderingThread::setSoftwareRenderer(SoftwareRenderer *softwareRenderer) {
	softwareMutex->lock();
	this->softwareRenderer = softwareRenderer;
	softwareMutex->unlock();
}

void RenderingThread::requestSurfaceResizing() {
	surfaceSizeChanged->setValue(true);
}

bool RenderingThread::isReady() const {
	return renderingOver->getValue();
}
void RenderingThread::prepareRendering() {
	renderingOver->setValue(false);
}
RenderingThread::~RenderingThread() {
	delete renderingOver;
	delete surfaceSizeChanged;
	delete renderingSurface;
	delete softwareMutex;
}

void RenderingThread::loopCode() {
	if (surfaceSizeChanged->getValue()) {
		delete renderingSurface;
		renderingSurface = new OSDL::Surface(window->getWidth(),
				window->getHeight());
		surfaceSizeChanged->setValue(false);
	}
	softwareMutex->lock();
	softwareRenderer->render(renderingSurface);
	softwareMutex->unlock();
	renderingOver->setValue(true);
	window->updateSurface(renderingSurface);
}

/*
 * Renderer.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "../Video/Renderer.hpp"

#include "../Software/SoftwareRenderer.hpp"

#include "../OSDL/Data/Atomic/AtomicBoolean.hpp"

#include "../OSDL/Resilience/Log.hpp"

#include "../OSDL/Thread/Mutex.hpp"

#include "../OSDL/Video/Window.hpp"
#include "../OSDL/Video/Surface.hpp"

Renderer::Renderer(OSDL::Window &window) {
	this->window = &window;

	softwareRenderer = nullptr;

	softwareMutex = new OSDL::Mutex;

	renderingSurface = new OSDL::Surface(window.getWidth(), window.getHeight());
	surfaceSizeChanged = new OSDL::AtomicBoolean(false);

	renderingOver = new OSDL::AtomicBoolean(true);
}

void Renderer::setSoftwareRenderer(SoftwareRenderer *softwareRenderer) {
	softwareMutex->lock();
	this->softwareRenderer = softwareRenderer;
	softwareMutex->unlock();
}

void Renderer::requestSurfaceResizing() {
	surfaceSizeChanged->setValue(true);
}

bool Renderer::isReady() const {
	return renderingOver->getValue();
}
void Renderer::prepareRendering() {
	renderingOver->setValue(false);
}
Renderer::~Renderer() {
	delete renderingOver;
	delete surfaceSizeChanged;
	delete renderingSurface;
	delete softwareMutex;
}

void Renderer::loopCode() {
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

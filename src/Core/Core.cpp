/*
 * Core.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "Core.hpp"

#include "../Software/Software.hpp"
#include "../Software/Menu/Menu.hpp"
#include "../Software/00 Snake/Snake.hpp"
#include "../Software/01 RayTracing/RayTracing.hpp"
#include "../Software/02 Chess/Chess.hpp"
#include "../Software/03 GameOfLife/GameOfLife.hpp"
#include "../Software/04 GPUMandelbrot/GPUMandelbrot.hpp"
#include "../Software/06 BombSweeper/BombSweeper.hpp"
#include "../Software/07 Text/Text.hpp"

#include "../OSDL/Resilience/Log.hpp"

#include "../OSDL/Time/Timer.hpp"

#include "../OSDL/Video/Window.hpp"

#include <cstdlib>
#include <ctime>

#include <sstream>
#include "../Video/RenderingThread.hpp"

Core::Core(RenderingThread &renderingThread, const OSDL::Window &window, float framerate) {
	this->renderingThread = &renderingThread;

	eventQueue = nullptr;

	software = new Menu();
	software->setWindowSize(window.getWidth(), window.getHeight());
	this->framerate = framerate;

	firstTick = 0;
	frame = 0;

	refreshDelay = 1000;
	refreshTick = 0;
	referenceFrame = 0;

	coreLags = 0;
	frameSkips = 0;

	renderingThread.setSoftwareRenderer(software->getSoftwareRenderer());
}

void Core::setEventQueue(OSDL::AtomicQueue *eventQueue) {
	this->eventQueue = eventQueue;
}

Core::~Core() {
	delete software;
}

void Core::initialize() {
	std::srand(std::time(nullptr));

	firstTick = OSDL::Timer::getTicks();

	refreshTick = firstTick + refreshDelay;

	iterate();
}

void Core::loopCode() {
	if (renderingThread->isReady()) {
		software->updateRenderingData();
		renderingThread->prepareRendering();
		renderingThread->iterate();
	} else {
		++frameSkips;
	}
	int32 delay = firstTick + 1000 * frame / framerate
			- OSDL::Timer::getTicks();
	if (delay > 0) {
		OSDL::Timer::delay(delay);
	} else if (delay < 0) {
		++coreLags;
	}
	if (OSDL::Timer::getTicks() >= refreshTick) {
		Uint16 realfp10s =
				0.5
						+ 10 * framerate
								* (1.0 * (referenceFrame - frameSkips)
										/ referenceFrame) * 1000.0
								* referenceFrame
								/ ((OSDL::Timer::getTicks() - refreshTick
										+ refreshDelay) * framerate);
		std::stringstream message;
		message << "Frame n°" << frame << " : "
				<< (Uint16) (0.5
						+ 100000.0 * referenceFrame
								/ ((OSDL::Timer::getTicks() - refreshTick
										+ refreshDelay) * framerate))
				<< "% speed, "
				<< (Uint16) (0.5 + 100 * coreLags / referenceFrame) << "% lag, "
				<< (Uint16) (0.5 + 100 * frameSkips / referenceFrame)
				<< "% frameskips, real framerate : " << realfp10s / 10 << "."
				<< realfp10s % 10 << "fps, desync : "
				<< (int) (frame * 1000 / framerate - OSDL::Timer::getTicks()
						+ firstTick) << "ms";
		OSDL::Log::startInfo() << message.str().c_str() << OSDL::Log::end;
		refreshTick = OSDL::Timer::getTicks() + refreshDelay;
		referenceFrame = 0;

		coreLags = 0;
		frameSkips = 0;
	}
	software->manageEvents(eventQueue);
	software->updateFrame();
	if (software->isOver()) {
		OSDL::Log::startInfo() << "Software change requested" << OSDL::Log::end;
		Software *newSoftware = nullptr;
		switch (software->getExitValue()) {
		case -1:
			newSoftware = new Menu();
			break;
		case 6:
			newSoftware = new BombSweeper();
			break;
		case 7:
			newSoftware = new Text();
			break;
		default:
			break;
		}
		if (newSoftware != nullptr) {
			newSoftware->importWindowSize(software);
			renderingThread->setSoftwareRenderer(newSoftware->getSoftwareRenderer());
			delete software;
			software = newSoftware;
		}
	}
	++frame;
	++referenceFrame;
	iterate();
}

void Core::quit() {
}


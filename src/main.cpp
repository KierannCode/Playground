/*
 * main.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "OSDL/Video/Window.hpp"

#include <SDL_Video.h>

#include "Event/EventManager.hpp"
#include <SDL_mutex.h>

#include "Core/CoreThread.hpp"
#include "OSDL/System.hpp"
#include "OSDL/Resilience/Log.hpp"
#include "Video/RenderingThread.hpp"

int main(int argc, char **argv) {
	OSDL::Log::setLevel(OSDL::LogLevel::DEBUG);

	OSDL::System::initialize();

	OSDL::Window window(768, 768, "Playground");

	SDL_DisplayMode mode;
	SDL_GetDesktopDisplayMode(0, &mode);

	RenderingThread renderingThread(window);
	CoreThread coreThread(renderingThread, window, mode.refresh_rate);
	EventManager eventManager(renderingThread, coreThread);

	renderingThread.start();
	coreThread.start();
	eventManager.start();

	coreThread.stop();
	renderingThread.stop();

	OSDL::System::quit();

	return 0;
}

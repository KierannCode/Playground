/*
 * main.cpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#include "OSDL/Video/Window.hpp"

#include <SDL_Video.h>

#include "Event/EventManager.hpp"
#include "Core/Core.hpp"
#include <SDL_mutex.h>

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
	Core core(renderingThread, window, mode.refresh_rate * 2);
	EventManager eventManager(renderingThread, core);

	renderingThread.start();
	core.start();
	eventManager.start();

	core.stop();
	renderingThread.stop();

	OSDL::System::quit();

	return 0;
}

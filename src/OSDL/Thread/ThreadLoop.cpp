/*
 * ThreadLoop.cpp
 *
 *  Created on: 29 juil. 2021
 *      Author: Kierann
 */

#include "ThreadLoop.hpp"

#include "../Data/Atomic/AtomicBoolean.hpp"
#include "../Resilience/Log.hpp"
#include "Semaphore.hpp"

#include <SDL_thread.h>

#include <exception>

using namespace OSDL;

void ThreadLoop::start() {
	running = new OSDL::AtomicBoolean(true);
	startIteration = new OSDL::Semaphore;
	thread = SDL_CreateThread(threadMethod, "", this);
}
void OSDL::ThreadLoop::iterate() {
	if (startIteration->getValue() == 0) {
		startIteration->increment();
	}
}
void OSDL::ThreadLoop::stop() {
	running->setValue(false);
	iterate();
	SDL_WaitThread(thread, NULL);
	delete startIteration;
	delete running;
}

OSDL::ThreadLoop::~ThreadLoop() {
}

int OSDL::threadMethod(void *data) {
	try {
		ThreadLoop *instance = (ThreadLoop*) (data);
		instance->initialize();
		instance->startIteration->wait();
		while (instance->running->getValue()) {
			instance->loopCode();
			instance->startIteration->wait();
		}
		instance->quit();
		return 0;
	} catch (std::exception &e) {
		OSDL::Log::error(e.what());
		return -1;
	}
}

void OSDL::ThreadLoop::initialize() {
}
void OSDL::ThreadLoop::loopCode() {
}
void OSDL::ThreadLoop::quit() {
}

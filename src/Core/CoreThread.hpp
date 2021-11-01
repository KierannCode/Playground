/*
 * CoreThread.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_CORETHREAD
#define PLAYGROUND_CORETHREAD

#include "../OSDL/Thread/ThreadLoop.hpp"

#include "../OSDL/Types.hpp"

class Software;
class RenderingThread;

namespace OSDL {
class AtomicQueue;
class Window;
}

/**
 * @brief The core thread
 *
 * @details Processes software events and software mechanics, monitors software performances
 * and controls the rendering thread frequency.\n
 * With optimal performances, the rendering thread will be synchronized with the core thread.
 *
 * @see RenderingThread
 */
class CoreThread: public OSDL::ThreadLoop {
public:
	/**
	 * @brief Value constructor
	 *
	 * @details Initializes the core thread.
	 *
	 * @param renderingThread The initialized rendering thread
	 *
	 * @param window The main window in which softwares will be rendered
	 *
	 * @param framerate The maximum core loop frequency
	 */
	CoreThread(RenderingThread &renderingThread, const OSDL::Window &window, float framerate);

	/**
	 * @brief EventQueue setter
	 *
	 * @details The event queue is created in the event manager, which must be initialized after the
	 * core thread. Thus the event queue must be manually set afterwards from the event manager.
	 *
	 * @param eventQueue A pointer to the event queue from the event manager
	 *
	 * @see EventManager
	 */
	void setEventQueue(OSDL::AtomicQueue *eventQueue);

	/**
	 * @brief destructor
	 *
	 * @details destroys the core thread. The core thread shall not be running when its destructor is called.\n
	 * @todo Add a warning when the destructor is called while the thread is still running.
	 */
	~CoreThread();
private:
	void initialize();
	void loopCode();
	void quit();

	RenderingThread *renderingThread;

	OSDL::AtomicQueue *eventQueue;

	Software *software;
	float framerate;

	OSDL::Time firstTick;
	uint32 frame;

	OSDL::Time refreshDelay;
	OSDL::Time refreshTick;
	uint32 referenceFrame;

	uint32 coreLags;
	uint32 frameSkips;
};

#endif /* PLAYGROUND_CORETHREAD */

/*
 * CoreThread.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef SRC_CORE_CORETHREAD_HPP_
#define SRC_CORE_CORETHREAD_HPP_

#include "../OSDL/Thread/ThreadLoop.hpp"

#include "../OSDL/Types.hpp"

class Software;
class RenderingThread;

namespace OSDL {
class AtomicQueue;
class Window;
}

class CoreThread: public OSDL::ThreadLoop {
public:
	CoreThread(RenderingThread &renderingThread, const OSDL::Window &window, float framerate);

	void setEventQueue(OSDL::AtomicQueue *eventQueue);

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

#endif /* SRC_CORE_CORETHREAD_HPP_ */

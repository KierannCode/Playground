/*
 * Software.hpp
 *
 *  Created on: 9 juil. 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_SOFTWARE
#define PLAYGROUND_SOFTWARE

#include "../OSDL/Event/EventTypes.hpp"

#include "../OSDL/Types.hpp"

class SoftwareRenderer;

namespace OSDL {
class AtomicQueue;
class Surface;
class Mutex;
}

class Software {
public:
	Software();

	void setWindowSize(OSDL::Size width, OSDL::Size height);
	void importWindowSize(Software *software);

	void manageEvents(OSDL::AtomicQueue *eventQueue);

	virtual void updateFrame();

	virtual void updateRenderingData();
	virtual SoftwareRenderer *getSoftwareRenderer() const = 0;

	bool isOver() const;
	int getExitValue() const;

	virtual ~Software();
protected:
	OSDL::Size windowWidth;
	OSDL::Size windowHeight;

	bool over;
	int exitValue;
private:
	virtual void onWindowResized(OSDL::Size width, OSDL::Size height);
	virtual void onMouseKeyPressed(OSDL::MouseKey key, int x, int y);
	virtual void onMouseMotion(int x, int y);
	virtual void onMouseKeyReleased(OSDL::MouseKey key, int x, int y);
	virtual void onKeyboardKeyPressed(OSDL::KeyboardKey key);
	virtual void onKeyboardKeyReleased(OSDL::KeyboardKey key);
};

#endif /* PLAYGROUND_SOFTWARE */

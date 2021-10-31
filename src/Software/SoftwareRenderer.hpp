/*
 * SoftwareRenderer.hpp
 *
 *  Created on: 10 août 2021
 *      Author: Kierann
 */

#ifndef PLAYGROUND_SOFTWARERENDERER
#define PLAYGROUND_SOFTWARERENDERER

namespace OSDL {
class Surface;
}

class SoftwareRenderer {
public:
	virtual void render(OSDL::Surface *surface);

	virtual ~SoftwareRenderer();
private:
	friend class Software;
};

#endif /* PLAYGROUND_SOFTWARERENDERER */

/*
 * SoftwareRenderer.hpp
 *
 *  Created on: 10 août 2021
 *      Author: Kierann
 */

#ifndef SRC_SOFTWARE_SOFTWARERENDERER_HPP_
#define SRC_SOFTWARE_SOFTWARERENDERER_HPP_

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

#endif /* SRC_SOFTWARE_SOFTWARERENDERER_HPP_ */

/*
 * Point2D.hpp
 *
 *  Created on: 6 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_VIDEO_GRAPHIC2D_POINT2D_HPP_
#define SRC_OSDL_VIDEO_GRAPHIC2D_POINT2D_HPP_

namespace OSDL {
class Point2D {
private:
	double x;
	double y;
public:
	Point2D();
	Point2D(double x, double y);

	double getX();
	double getY();

	void setX(double x);
	void setY(double y);
};
}

#endif /* SRC_OSDL_VIDEO_GRAPHIC2D_POINT2D_HPP_ */

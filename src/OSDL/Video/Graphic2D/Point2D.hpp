/*
 * Point2D.hpp
 *
 *  Created on: 6 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_POINT2D
#define OSDL_POINT2D

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

#endif /* OSDL_POINT2D */

/*
 * Data.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_DATA_DATA_HPP_
#define SRC_OSDL_DATA_DATA_HPP_

namespace OSDL {
class Data {
public:
	virtual OSDL::Data* createCopy() const = 0;

	virtual ~Data();
};
}

#endif /* SRC_OSDL_DATA_DATA_HPP_ */

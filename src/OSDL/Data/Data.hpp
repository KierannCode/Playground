/*
 * Data.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_DATA_DATA_HPP_
#define SRC_OSDL_DATA_DATA_HPP_

namespace OSDL {

/**
 * @brief Basic data interface
 *
 * @details This interface is used in some data structures to allow polymorphism without using templates.
 */
class Data {
public:
	/**
	 * @brief Creates a copy of the OSDL::Data object
	 *
	 * @details This method returns a pointer to a new copy of the OSDL::Data object.\n
	 * It is pure virtual and must be implemented in any derived class of OSDL::Data.\n
	 * The copy is allocated with 'new' and must be manually destroyed using 'delete'.\n
	 * For consistency, if DerivedClass is a derived class of OSDL::Data, its implementatio by default shall be as follows :
	 * \code{.cpp}
	 * DerivedClass *DerivedClass::createCopy() {
	 *     return new DerivedClass(*this)';
	 * }
	 * \endcode
	 *
	 * @return A pointer to a copy of the OSDL::Data object.
	 */
	virtual OSDL::Data* createCopy() const = 0;

	/**
	 * @brief OSDL::Data destructor
	 *
	 * @details This destructor is mandatory since OSDL::Data is abstract, but does nothing since the class OSDL::Data does not contain any attribute.
	 */
	virtual ~Data();
};
}

#endif /* SRC_OSDL_DATA_DATA_HPP_ */

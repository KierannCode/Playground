/*
 * AtomicBoolean.hpp
 *
 *  Created on: 19 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_DATA_ATOMIC_ATOMICBOOLEAN_HPP_
#define SRC_OSDL_DATA_ATOMIC_ATOMICBOOLEAN_HPP_

namespace OSDL {
class Mutex;
class AtomicBoolean {
public:
	AtomicBoolean() = delete;
	AtomicBoolean(bool value);

	bool getValue() const;
	void setValue(bool value);

	~AtomicBoolean();
private:
	bool value;
	OSDL::Mutex *mutex;
};
}

#endif /* SRC_OSDL_DATA_ATOMIC_ATOMICBOOLEAN_HPP_ */

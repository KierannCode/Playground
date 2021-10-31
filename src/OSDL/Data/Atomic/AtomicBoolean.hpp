/*
 * AtomicBoolean.hpp
 *
 *  Created on: 19 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_ATOMICBOOLEAN
#define OSDL_ATOMICBOOLEAN

namespace OSDL {
class Mutex;

/**
 * @brief Thread-safe boolean.
 *
 * @details A thread-safe implementation of a boolean object.
 */
class AtomicBoolean {
public:
	/**
	 * @brief OSDL::AtomicBoolean default constructor.
	 *
	 * @details Initializes the value of the boolean with 'false'.
	 */
	AtomicBoolean();
	/**
	 * @brief OSDL::AtomicBoolean value constructor.
	 *
	 * @details Initializes the value of the boolean with the specified value.
	 *
	 * @param value The boolean value used to initialize the boolean.
	 */
	AtomicBoolean(bool value);

	/**
	 * @brief Thread-safe getter.
	 *
	 * @details Getter that can be used safely in different threads.
	 *
	 * @return The value of the boolean.
	 */
	bool getValue() const;
	/**
	 * @brief Thread-safe setter.
	 *
	 * @details Setter that can be used safely in different threads.
	 *
	 * @param value The new boolean value.
	 */
	void setValue(bool value);

	/**
	 * @brief OSDL::AtomicBoolean destructor.
	 *
	 * @details Destroys the boolean.
	 */
	~AtomicBoolean();
private:
	bool value;
	OSDL::Mutex *mutex;
};
}

#endif /* OSDL_ATOMICBOOLEAN */

/*
 * SinglyLinkedElement.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_DATA_SINGLYLINKEDELEMENT_HPP_
#define SRC_OSDL_DATA_SINGLYLINKEDELEMENT_HPP_

namespace OSDL {
class Data;

class SinglyLinkedElement {
public:
	SinglyLinkedElement() = delete;
	SinglyLinkedElement(const OSDL::Data &data);

	OSDL::Data &getData();

	OSDL::SinglyLinkedElement* getNextElement();
	void link(OSDL::SinglyLinkedElement *element);
	void isolate();

	~SinglyLinkedElement();
private:
	OSDL::Data *data;

	OSDL::SinglyLinkedElement *nextElement;
};
}

#endif /* SRC_OSDL_DATA_SINGLYLINKEDELEMENT_HPP_ */

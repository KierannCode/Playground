/*
 * SinglyLinkedElement.cpp
 *
 *  Created on: 4 sept. 2021
 *      Author: Kierann
 */

#include "SinglyLinkedElement.hpp"

#include "Data.hpp"

#include "../Resilience/Exception/IllegalCallException.hpp"

OSDL::SinglyLinkedElement::SinglyLinkedElement(const OSDL::Data &data) {
	this->data = data.createCopy();
	nextElement = nullptr;
}

OSDL::Data& OSDL::SinglyLinkedElement::getData() {
	return *data;
}

OSDL::SinglyLinkedElement* OSDL::SinglyLinkedElement::getNextElement() {
	return nextElement;
}
void OSDL::SinglyLinkedElement::link(OSDL::SinglyLinkedElement *element) {
	if (nextElement) {
		throw OSDL::IllegalCallException(
				"Cannot call method 'link()' in class 'SinglyLinkedElement' because the next element is already set. You must isolate the element first");
	}
	nextElement = element;
}
void OSDL::SinglyLinkedElement::isolate() {
	nextElement = nullptr;
}

OSDL::SinglyLinkedElement::~SinglyLinkedElement() {
	delete data;
}


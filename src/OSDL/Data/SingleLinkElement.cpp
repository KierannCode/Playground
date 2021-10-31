/*
 * SingleLinkElement.cpp
 *
 *  Created on: 4 sept. 2021
 *      Author: Kierann
 */

#include "Data.hpp"

#include "../Resilience/Exception/IllegalCallException/IllegalCallException.hpp"
#include "SingleLinkElement.hpp"

OSDL::SingleLinkElement::SingleLinkElement(const OSDL::Data &data) {
	this->data = data.createCopy();
	nextElement = nullptr;
}

OSDL::Data& OSDL::SingleLinkElement::getData() {
	return *data;
}

OSDL::SingleLinkElement* OSDL::SingleLinkElement::getNextElement() {
	return nextElement;
}
void OSDL::SingleLinkElement::link(OSDL::SingleLinkElement *element) {
	if (nextElement) {
		throw OSDL::IllegalCallException(
				"Cannot call method 'link()' in class 'SinglyLinkedElement' because the next element is already set. You must isolate the element first");
	}
	nextElement = element;
}
void OSDL::SingleLinkElement::isolate() {
	nextElement = nullptr;
}

OSDL::SingleLinkElement::~SingleLinkElement() {
	delete data;
}


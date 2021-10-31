/*
 * SingleLinkElement.hpp
 *
 *  Created on: 2 sept. 2021
 *      Author: Kierann
 */

#ifndef OSDL_SINGLELINKELEMENT
#define OSDL_SINGLELINKELEMENT

namespace OSDL {
class Data;

class SingleLinkElement {
public:
	SingleLinkElement() = delete;
	SingleLinkElement(const OSDL::Data &data);

	OSDL::Data &getData();

	OSDL::SingleLinkElement* getNextElement();
	void link(OSDL::SingleLinkElement *element);
	void isolate();

	~SingleLinkElement();
private:
	OSDL::Data *data;

	OSDL::SingleLinkElement *nextElement;
};
}

#endif /* OSDL_SINGLELINKELEMENT */

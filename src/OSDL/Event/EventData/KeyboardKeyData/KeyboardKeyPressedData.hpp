/*
 * KeyboardKeyPressedData.hpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_KEYBOARDKEYPRESSEDDATA
#define OSDL_KEYBOARDKEYPRESSEDDATA

#include "../KeyboardKeyData.hpp"

namespace OSDL {
class KeyboardKeyPressedData: public KeyboardKeyData {
public:
	KeyboardKeyPressedData() = delete;
	KeyboardKeyPressedData(OSDL::KeyboardKey key);

	OSDL::KeyboardKeyPressedData* createCopy() const;

	OSDL::EventType getEventType() const;
};
}

#endif /* OSDL_KEYBOARDKEYPRESSEDDATA */

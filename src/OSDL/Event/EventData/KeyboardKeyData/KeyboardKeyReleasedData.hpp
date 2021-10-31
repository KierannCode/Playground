/*
 * KeyboardKeyReleasedData.hpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_KEYBOARDKEYRELEASEDDATA
#define OSDL_KEYBOARDKEYRELEASEDDATA

#include "../KeyboardKeyData.hpp"

namespace OSDL {
class KeyboardKeyReleasedData: public KeyboardKeyData {
public:
	KeyboardKeyReleasedData() = delete;
	KeyboardKeyReleasedData(OSDL::KeyboardKey key);

	OSDL::KeyboardKeyReleasedData* createCopy() const;

	OSDL::EventType getEventType() const;
};
}

#endif /* OSDL_KEYBOARDKEYRELEASEDDATA */

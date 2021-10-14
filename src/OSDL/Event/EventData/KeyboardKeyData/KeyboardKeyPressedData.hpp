/*
 * KeyboardKeyPressedData.hpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_KEYBOARDKEYDATA_KEYBOARDKEYPRESSEDDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_KEYBOARDKEYDATA_KEYBOARDKEYPRESSEDDATA_HPP_

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

#endif /* SRC_OSDL_EVENT_EVENTDATA_KEYBOARDKEYDATA_KEYBOARDKEYPRESSEDDATA_HPP_ */

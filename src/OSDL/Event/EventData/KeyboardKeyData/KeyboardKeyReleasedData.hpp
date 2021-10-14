/*
 * KeyboardKeyReleasedData.hpp
 *
 *  Created on: 30 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_KEYBOARDKEYDATA_KEYBOARDKEYRELEASEDDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_KEYBOARDKEYDATA_KEYBOARDKEYRELEASEDDATA_HPP_

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

#endif /* SRC_OSDL_EVENT_EVENTDATA_KEYBOARDKEYDATA_KEYBOARDKEYRELEASEDDATA_HPP_ */

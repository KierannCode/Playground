/*
 * KeyboardKeyData.hpp
 *
 *  Created on: 29 août 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_KEYBOARDKEYDATA_HPP_
#define SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_KEYBOARDKEYDATA_HPP_

#include "../EventData.hpp"

#include "../EventTypes.hpp"

namespace OSDL {
class KeyboardKeyData : public OSDL::EventData {
private:
	OSDL::KeyboardKey key;
public:
	KeyboardKeyData(OSDL::KeyboardKey key);

	OSDL::KeyboardKey getKey();
};
}

#endif /* SRC_OSDL_EVENT_EVENTDATA_MOUSEKEYDATA_KEYBOARDKEYDATA_HPP_ */

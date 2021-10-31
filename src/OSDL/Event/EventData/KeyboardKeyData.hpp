/*
 * KeyboardKeyData.hpp
 *
 *  Created on: 29 août 2021
 *      Author: Kierann
 */

#ifndef OSDL_KEYBOARDKEYDATA
#define OSDL_KEYBOARDKEYDATA

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

#endif /* OSDL_KEYBOARDKEYDATA */

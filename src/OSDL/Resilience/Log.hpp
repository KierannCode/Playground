/*
 * Log.hpp
 *
 *  Created on: 5 oct. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_RESILIENCE_LOG_HPP_
#define SRC_OSDL_RESILIENCE_LOG_HPP_

#include <sstream>

namespace OSDL {
class Mutex;

enum class LogLevel {
	NONE = 0, ERROR = 1, WARNING = 2, INFO = 3, DEBUG = 4
};

class Log {
public:
	static void setLevel(LogLevel logLevel);

	static void error(const char *message);
	static void warning(const char *message);
	static void info(const char *message);
	static void debug(const char *message);
	static std::ostream& startError();
	static std::ostream& startWarning();
	static std::ostream& startInfo();
	static std::ostream& startDebug();

	static std::ostream& end(std::ostream &ostream);
private:
	static void outputTimestamp();
	static void outputThreadID();

	static std::stringstream errorStream;
	static std::stringstream warningStream;
	static std::stringstream infoStream;
	static std::stringstream debugStream;

	static OSDL::Mutex &mutex;

	static OSDL::LogLevel level;
};
}

#endif /* SRC_OSDL_RESILIENCE_LOG_HPP_ */

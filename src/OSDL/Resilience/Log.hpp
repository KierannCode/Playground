/*
 * Log.hpp
 *
 *  Created on: 5 oct. 2021
 *      Author: Kierann
 */

#ifndef SRC_OSDL_RESILIENCE_LOG_HPP_
#define SRC_OSDL_RESILIENCE_LOG_HPP_

namespace OSDL {
class Mutex;

enum class LogLevel {
	NONE = 0, ERROR = 1, WARNING = 2, INFO = 3, DEBUG = 4
};

/// TODO : Allow formatted inputs in logs.
class Log {
public:
	static void setLevel(LogLevel logLevel);

	static void error(const char *message);
	static void warning(const char *message);
	static void info(const char *message);
	static void debug(const char *message);
private:
	static void outputTimestamp();
	static void outputThreadID();

	static OSDL::Mutex &mutex;

	static OSDL::LogLevel level;
};
}

#endif /* SRC_OSDL_RESILIENCE_LOG_HPP_ */

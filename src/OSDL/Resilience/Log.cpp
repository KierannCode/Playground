/*
 * Log.cpp
 *
 *  Created on: 5 oct. 2021
 *      Author: Kierann
 */

#include "Log.hpp"

#include "../Types.hpp"

#include "../Thread/Mutex.hpp"

#include <SDL_thread.h>

#include <iostream>
#include <ctime>

OSDL::Mutex &OSDL::Log::mutex = OSDL::Mutex();

OSDL::LogLevel OSDL::Log::level = OSDL::LogLevel::ERROR;

void OSDL::Log::setLevel(OSDL::LogLevel logLevel) {
	level = logLevel;
}

void OSDL::Log::error(const char *message) {
	mutex.lock();
	if (level >= OSDL::LogLevel::ERROR) {
		outputTimestamp();
		std::cout << "\033[1;31m ERROR : In thread \033[0m";
		outputThreadID();
		std::cout << "\033[1;31m : " << message << "\033[0m" << std::endl;
	}
	mutex.unlock();
}
void OSDL::Log::warning(const char *message) {
	mutex.lock();
	if (level >= OSDL::LogLevel::WARNING) {
		outputTimestamp();
		std::cout << "\033[1;33m WARNING : In thread \033[0m";
		outputThreadID();
		std::cout << "\033[1;33m : " << message << "\033[0m" << std::endl;
	}
	mutex.unlock();
}
void OSDL::Log::info(const char *message) {
	mutex.lock();
	if (level >= OSDL::LogLevel::INFO) {
		outputTimestamp();
		std::cout << "\033[1;92m INFO : In thread \033[0m";
		outputThreadID();
		std::cout << "\033[1;92m : " << message << "\033[0m" << std::endl;
	}
	mutex.unlock();
}
void OSDL::Log::debug(const char *message) {
	mutex.lock();
	if (level >= OSDL::LogLevel::DEBUG) {
		outputTimestamp();
		std::cout << "\033[1;94m DEBUG : In thread \033[0m";
		outputThreadID();
		std::cout << "\033[1;94m : " << message << "\033[0m" << std::endl;
	}
	mutex.unlock();
}

void OSDL::Log::outputTimestamp() {
	std::time_t time = std::time(0);
	std::tm *now = std::localtime(&time);
	std::cout << '[' << now->tm_year + 1900 << '-';
	if (now->tm_mon <= 8) {
		std::cout << '0';
	}
	std::cout << now->tm_mon + 1 << '-';
	if (now->tm_mday <= 9) {
		std::cout << '0';
	}
	std::cout << now->tm_mday << ' ';
	if (now->tm_hour <= 9) {
		std::cout << '0';
	}
	std::cout << now->tm_hour << ':';
	if (now->tm_min <= 9) {
		std::cout << '0';
	}
	std::cout << now->tm_min << ':';
	if (now->tm_sec <= 9) {
		std::cout << '0';
	}
	std::cout << now->tm_sec << "]";
}
void OSDL::Log::outputThreadID() {
	srand(SDL_ThreadID());
	uint8 red = rand() & 0xff;
	uint8 green = rand() & 0xff;
	uint8 blue = rand() & 0xff;
	std::cout << "\033[38;2;" << (int) red << ";" << (int) green << ";"
			<< (int) blue << ";48;2;" << (int) ((uint8) (red + 128)) << ";"
			<< (uint16) ((uint8) (green + 128)) << ";"
			<< (uint16) ((uint8) (blue + 128)) << "m" << SDL_ThreadID()
			<< "\033[0m";
}

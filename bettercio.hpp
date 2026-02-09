//Yes this is literally just io.write and what not from lua, atleast its simpler than std << cout
// do whatever u want with it but atleast give credits to me ( ͡° ͜ʖ ͡°)
// Made by @JustJazzFR

#ifndef BETTERCIO_HPP
#define BETTERCIO_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace io {

	//Write to console (no flush)
	template <typename T>
	void write(const T& data) {
		std::cout << data;
	}

	//Write to console (new line + flush)
	template <typename T>
	void writef(const T& data) {
		std::cout << data << std::endl;
	}

	//read from console
	template <typename T>
	void in(T& var) {
		std::getline(std::cin >> std::ws, var);
	}

	//read a file into a string
	template <typename T>
	inline std::string read(const std::string &file_n) {
		std::ifstream file(file_n);
		if (!file) {
			throw std::runtime_error("Cannot open file: " + file_n);
		}
		std::ostringstream ss;
		ss << file.rdbuf();

		return ss.str();
	}

	//write a string to a file
	template <typename T>
	inline void writeto (const std::string &file_n, const std::string &data, bool append = false) {
		std::ofstream file(file_n, append ? std::ios_base::app : std::ios_base::out);
		if (!file) {
			throw std::runtime_error("Cannot open file: " + file_n);
		}
		file << data;
	}
}

#endif

#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <chrono>
#include <random>
#include <string>
#include <string_view>
#include <iostream>
#include <fstream>

namespace Random
{
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		// Create seed_seq with clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	
	inline std::mt19937 mt{ generate() }; 

	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{min, max}(mt);
	}

	template <typename T>
	T get(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	template <typename R, typename S, typename T>
	R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}

    inline std::string_view getWordFromCSV(const std::string& filename){
        std::ifstream file {};
		std::size_t line_number {};

		std::vector<std::string> words{};

		std::cout<< "Extracting from file: " << filename << '\n';
		file.open(filename);

		if (file.fail()){
			std::cout << "File failed to open\n";
			std::abort;
		}
		std::string line {};

		while (!file.eof()){
			std::getline(file,line, ',');
			words.emplace_back(line);
		}

		file.close();
		line_number = get(0, words.size()-1);
		std::string random_word {words[line_number]};
		random_word.erase(0,1);
		
		return random_word;
    }
}

#endif
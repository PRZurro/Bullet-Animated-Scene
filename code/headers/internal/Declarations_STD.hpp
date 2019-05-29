/**
 * @file Declarations_STD.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 23-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_DECLARATIONS_STD_H_
#define BULLET_ANIMATED_SCENE_DECLARATIONS_STD_H_

#include <chrono>
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include <iostream>
#include <fstream>

#include <cassert>
#include <cstddef>         // std::size_t

using namespace std;

namespace prz
{

	template<typename T>
	using PSPtr = std::shared_ptr<T>; // Shared pointer

	template<typename Key, typename Val>
	using PMap = std::unordered_map<Key, Val>;

	template<typename T>
	using PBuffer = std::vector<T>; // Same as vector but renamed

	template<typename T>
	using PList = std::list<T>;

	template<typename T>
	using PInitList = std::initializer_list<T>;

	using PString = std::string;

	using HighClock = std::chrono::high_resolution_clock;
	using HighTimePoint = std::chrono::time_point<HighClock>;

	using ElapsedTime =  std::chrono::duration<double>;

	using PHighClock = std::chrono::high_resolution_clock;
	using PTimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
	using PElapsedTime =std::chrono::duration<double>;
} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_DECLARATIONS_STD_H_

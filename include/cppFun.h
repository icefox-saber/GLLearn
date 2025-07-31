#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

template <typename DestT>
DestT readFile(const std::filesystem::path& filePath);

template<>
std::string readFile<std::string>(const std::filesystem::path& filePath);
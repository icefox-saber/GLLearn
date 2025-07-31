#include <string>
#include "cppFun.h"

template<>
std::string readFile<std::string>(const std::filesystem::path& filePath) {
    //std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filePath.string());
    }
    
    // 使用filesystem获取文件大小，避免seek操作
    const auto fileSize = std::filesystem::file_size(filePath);
    std::string content(fileSize, '\0');
    file.read(content.data(), fileSize);
    file.close();
    
    return content;
}

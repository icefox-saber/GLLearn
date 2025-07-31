#include <fstream>
#include <string>
#include <filesystem>

std::string readFileToString(const std::filesystem::path& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filePath.string());
    }
    
    // 使用filesystem获取文件大小，避免seek操作
    const auto fileSize = std::filesystem::file_size(filePath);
    std::string content(fileSize, '\0');
    file.read(content.data(), fileSize);
    
    return content;
}
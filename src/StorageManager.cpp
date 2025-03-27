#include "StorageManager.h"
#include <iostream>

std::fstream StorageManager::openFile(const std::string& filename, std::ios_base::openmode mode) {
    std::fstream file(filename, mode);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return file;
}

bool StorageManager::isFileOpen(std::fstream& file) {
    return file.is_open();
}

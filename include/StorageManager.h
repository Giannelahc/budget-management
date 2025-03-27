#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <fstream>
#include <iostream>
#include <string>

class StorageManager {
public:
    // Método para abrir un archivo en modo de lectura y escritura binaria
    static std::fstream openFile(const std::string& filename, std::ios_base::openmode mode);

    template <typename T>
    static void readObject(std::fstream& file, T& object) {
        if (file.is_open()) {
            object.deserialize(file);
        } else {
            std::cerr << "File is not open" << std::endl;
        }
    }

    template <typename T>
    static void writeObject(std::fstream& file, const T& object) {
        if (file.is_open()) {
            object.serialize(file);
        } else {
            std::cerr << "File is not open" << std::endl;
        }
    }

    // Método para verificar si el archivo está abierto
    static bool isFileOpen(std::fstream& file);
};

#endif

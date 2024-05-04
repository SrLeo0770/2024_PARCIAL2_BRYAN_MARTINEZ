#include <iostream>
#include <filesystem>
#include <fstream>
#include <windows.h>

namespace fs = std::filesystem;

void createFiles(int numFiles) {
    std::string basePath = "C:\\Users\\leode\\Desktop\\";
    std::string subfolder;
    if (numFiles % 2 == 0)
        subfolder = "par";
    else
        subfolder = "impar";

    basePath += subfolder;

    if (!fs::exists(basePath))
        fs::create_directory(basePath);

    for (int i = 1; i <= numFiles; ++i) {
        std::string filePath = basePath + "\\file" + std::to_string(i) + ".txt";
        std::ofstream file(filePath);
        if (file.is_open()) {
            for (int j = 0; j < i; ++j) {
                file << "Linea " << j + 1 << " del archivo " << i << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error al abrir el archivo: " << filePath << std::endl;
        }
    }

    std::cout << numFiles << " archivos creados en la carpeta " << subfolder << std::endl;
}

int main() {
    int numFiles;
    std::cout << "Ingrese la cantidad de archivos que desea crear: ";
    std::cin >> numFiles;

    createFiles(numFiles);

    system("pause");
    return 0;
}
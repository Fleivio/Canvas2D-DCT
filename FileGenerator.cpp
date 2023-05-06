
#include <string>
#include <fstream>
#include <ctime>

int main(){
    std::string fileName = "input.dct";
    int size = 30;
    srand(time(nullptr));

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (int i = 0; i < size; ++i)
        {
            char randomChar = rand() % 256;
            file.write(&randomChar, sizeof(randomChar));
        }
        
        file.close();
    }

    return 0;
}
#include "FileHandler.h"

void FileHandler::save(const std::vector<char> &vec, const string &fileName)
{
    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char *>(vec.data()), vec.size());
        file.close();
    }
}

vector<char> FileHandler::load(const string &fileName)
{
    ifstream file(fileName, ios::binary);

    if (file.is_open())
    {

        file.seekg(0, ios::end);
        size_t fileSize = file.tellg();
        file.seekg(0, ios::beg);

        vector<char> fileContent(fileSize);
        file.read(fileContent.data(), fileSize);

        file.close();

        return fileContent;
    }
    puts("nao abriu o arquivo");
    return vector<char>();
}
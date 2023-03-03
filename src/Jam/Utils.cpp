#include <Jam/Utils.h>
using namespace std;

string Jam::get_file_contents(string path)
{
    fstream file;
    file.open(path);

    if(file)
    {
        string data;

        file.seekg(0, ios::end);
        data.resize(file.tellg());
        file.seekg(0, ios::beg);

        file.read(&data[0], data.size());

        file.close();

        return data;
    }
    else
    {
        return "";
    }
}
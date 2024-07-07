#include <iostream>
#include <fstream>
#include <string>

void countBytes(std::istream& stream);
void countLines(std::istream& stream);
void countWords(std::istream& stream);
void countChars(std::istream& stream);

using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2){
        std::cerr << "Usage: " << argv[0] << " <option> [filename]" << std::endl;
        std::cerr << "Options: -c (bytes), -l (lines), -w (words), -m (characters)" << std::endl;
        return 1;
    }

    string option = argv[1];
    istream* inputStream = &cin;
    ifstream fileStream;

    if(argc == 3) {
        string filename = argv[2];
        fileStream.open(filename);
        if(!fileStream){
            std::cerr << "Error: File not found" << std::endl;
            return 1;
        }
        inputStream = &fileStream;
    }

    if(option == "-c"){
        countBytes(*inputStream);
    } else if(option == "-l"){
        countLines(*inputStream);
    } else if(option == "-w"){
        countWords(*inputStream);
    } else if(option == "-m"){
        countChars(*inputStream);
    } else {
        std::cerr << "Unknown option: " << option << std::endl;
        return 1;
    }

    if (fileStream.is_open()) {
        fileStream.close();
    }

    return 0;
}

void countBytes(std::istream& stream){
    stream.seekg(0, ios::end);
    int size = stream.tellg();
    stream.seekg(0, ios::beg);  // Reset the stream position to the beginning
    std::cout << size << std::endl;
}

void countLines(std::istream& stream){
    int count = 0;
    std::string line;
    while(getline(stream, line)){
        count++;
    }
    std::cout << count << std::endl;
}

void countWords(std::istream& stream){
    int count = 0;
    std::string word;
    while(stream >> word){
        count++;
    }
    std::cout << count << std::endl;
}

void countChars(std::istream& stream){
    int count = 0;
    char c;
    while(stream.get(c)){
        count++;
    }
    std::cout << count << std::endl;
}

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::cout;
using std::endl;
using std::string;

void fileWrite(string fileName, std::vector<string> v){
    if(access(fileName.c_str(), 0) != -1){
        cout << fileName << " found" << endl;
    } else{
        cout << fileName << " is created" << endl;
    }
    ofstream fs(fileName, std::ios_base::app);
    char newline = '\n';
    for(int i = 0; i < v.size(); i++) {
        fs.write(v[i].c_str(), v[i].size());
        fs.write(&newline, 1);
    }
    fs.close();
}
void fileRead(const char* fileName){
    ifstream fs(fileName);
    if(fs.fail()){
        cout << "fail to open " << fileName << " file" << endl;
        return;
    }
    std::vector<string> contents;
    while(!fs.eof()){
        string file_content;
        getline(fs, file_content);
        cout << file_content << endl;
        contents.push_back(file_content);
    }
    string saved_fileName;
    cout << endl << "enter file name to save the contents: ";
    std::cin >> saved_fileName;
    fileWrite(saved_fileName, contents);

    fs.close();
}
int main(){
    fileRead("14-7.cpp");
    return 0;
}

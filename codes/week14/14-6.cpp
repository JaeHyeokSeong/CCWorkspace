#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::getline;
using std::string;

void file_write(const char* fn){
    // 파일에 내용 쓰기
    // 파일에다가 내용을 추가하기 위해서는 std::ios_base::app 을 사용해줘야 한다
    ofstream ofs(fn, std::ios_base::app);
    // 만약 파일을 오픈하는데 있어서 실패하면 에러 메시지 출력하기
    if(ofs.fail()){
        cout << "fail to open " << fn << " file" << endl;
        return;
    }
    string file_content;
    // 사전에 어떠한 enter 값이 있으면 그 값을 지워줘야한다
    // 만약에 사전에 있던 enter 값을 지워주지 안흥면 아래에 있는 getline이 작동되어지지 않는다
    // 이때는 아래에 있는 코드를 활성화 시켜줘야 한다
    // cin.ignore(); 

    cout << "enter text: ";
    getline(cin, file_content);
    file_content += '\n';
    /*
    write() 함수를 사용할때 첫번째 인자로 const char* 를 보내줘야한다
    이때 string 을 const char* 로 바꿔주는 함수가 c_str() 이다
    */
    ofs.write(file_content.c_str(), file_content.size());
    // 파일 스트림 다 사용한 후 닫아주기
    ofs.close();
}
void file_read(const char* fn){
    // 파일 내용 읽기
    ifstream ifs(fn);
    // 만약 파일을 오픈하는데 있어서 실패하면 에러 메시지 출력하기
    if(ifs.fail()){
        cout << "fail to open " << fn << " file" << endl;
        return;
    }
    /*
    파일의 끝에 도달하게 되면 true 리턴
    아직 읽을 내용이 존재하면 false 리턴 
    */
    while(!ifs.eof()){
        string file_content;
        getline(ifs, file_content);
        cout << file_content << endl;
    }
    // 파일 스트림을 다사용한 다음에는 반드시 닫아줘야 한다
    ifs.close();
}
int main(){
    const char* fn = "test.txt";
    string test;
    cout << "테스트: ";
    cin >> test;
    cin.ignore(); // 버퍼 값 지우기
    file_write(fn);
    file_write(fn);
    file_read(fn);
    return 0;
}
#include <iostream>
#include <map>
#include <vector>

int main(){
    std::map<int, std::string> products;
    // key 값에 의해서 map object 에 들어가는 값들이 오름차순으로 자동으로 정렬이 되어진다.
    products.insert(std::pair<int, std::string>(1, "lg tv"));
    products.insert(std::pair<int, std::string>(0, "apple iphone"));
    if(products.find(1) != products.end())
        std::cout << "found\n";
    else    
        std::cout << "not found\n";

    for(std::map<int, std::string>::iterator it = products.begin(); it != products.end(); it++){
        std::cout << it->first << ' ' << it->second << '\n';
    }
    std::cout << "after updating key value 0 product name\n";
    products[0] = "samsung tv";
    for(std::map<int, std::string>::iterator it = products.begin(); it != products.end(); it++){
        std::cout << it->first << ' ' << it->second << '\n';
    }
    products[2] = "apple tv"; 
    // 다른 방법으로 삽입하는 방법 이때 key 값이 이미 존재하는 거면 value 값을 업데이트 해준다.
    std::cout << "insert new product\n";
    for(std::map<int, std::string>::iterator it = products.begin(); it != products.end(); it++){
        std::cout << it->first << ' ' << it->second << '\n';
    }
    int key = 0;
    std::cout << "키 값을 입력해주세요: ";
    std::cin >> key;
    if(products.find(key) != products.end())
        std::cout << "value: " << products[key] << '\n';
    else    
        std::cout << "not found\n";

    std::map<int, std::vector<std::string> > classes;
    std::vector<std::string> class1_names;
    class1_names.push_back("학생1");
    class1_names.push_back("학생2");
    class1_names.push_back("학생3");
    class1_names.push_back("학생4");
    classes.insert(std::make_pair(1, class1_names));

    if(classes.find(1) != classes.end()){
        std::string student_name;
        for(int i = 0; i < classes[1].size(); i++){
            std::cout << classes[1][i] << '\n';
        }
    }
    return 0;
}
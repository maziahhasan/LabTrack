#include <iostream>
#include <functional>
#include <string>
int main(int argc, char** argv) {
    if (argc < 2) { std::cerr << "Usage: hash_pw <password>\n"; return 1; }
    std::string pw = argv[1];
    std::hash<std::string> h;
    std::cout << h(pw) << std::endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <functional>

static void writeString(std::ofstream &out, const std::string &s) {
    int len = (int)s.size();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: create_user <username> <password> [role] [email]\n";
        return 1;
    }
    std::string username = argv[1];
    std::string password = argv[2];
    std::string role = (argc >= 4) ? argv[3] : "AcademicOfficer";
    std::string email = (argc >= 5) ? argv[4] : "";

    std::hash<std::string> h;
    std::string hash = std::to_string(h(password));

    std::ofstream out("users.bin", std::ios::binary | std::ios::trunc);
    if (!out.is_open()) { std::cerr << "Failed to open users.bin for writing\n"; return 2; }
    int count = 1;
    out.write((char*)&count, sizeof(count));
    int id = 1; out.write((char*)&id, sizeof(id));
    writeString(out, username);
    writeString(out, hash);
    writeString(out, role);
    writeString(out, email);
    writeString(out, std::string("Active"));
    out.close();
    std::cout << "Created users.bin with user: " << username << " role=" << role << "\n";
    return 0;
}

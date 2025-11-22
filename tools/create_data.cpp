#include <fstream>
#include <string>
#include <vector>
using namespace std;

void writeString(ofstream &out, const string &s) {
    int len = (int)s.size();
    out.write((char*)&len, sizeof(len));
    out.write(s.c_str(), len);
}

void write_tas() {
    ofstream out("tas.bin", ios::binary | ios::trunc);
    int size = 1; out.write((char*)&size, sizeof(size));
    int id = 1; out.write((char*)&id, sizeof(id));
    string name = "ta1"; int len = name.size(); out.write((char*)&len, sizeof(len)); out.write(name.c_str(), len);
}

void write_instructors() {
    ofstream out("instructors.bin", ios::binary | ios::trunc);
    int size = 1; out.write((char*)&size, sizeof(size));
    int id = 1; out.write((char*)&id, sizeof(id));
    string name = "instr1"; writeString(out, name);
}

void write_hods() {
    ofstream out("hods.bin", ios::binary | ios::trunc);
    int size = 1; out.write((char*)&size, sizeof(size));
    int id = 1; out.write((char*)&id, sizeof(id));
    string name = "hod1"; writeString(out, name);
    string dept = ""; writeString(out, dept);
}

void write_acos() {
    ofstream out("academic_officers.bin", ios::binary | ios::trunc);
    int size = 1; out.write((char*)&size, sizeof(size));
    int id = 1; out.write((char*)&id, sizeof(id));
    string name = "ao1"; writeString(out, name);
}

int main(){ write_tas(); write_instructors(); write_hods(); write_acos(); return 0; }

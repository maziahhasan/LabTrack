#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>

int main(){
    std::ifstream in("users.txt");
    if(!in){ std::cerr<<"users.txt not found"<<std::endl; return 1; }
    std::string line;
    while(std::getline(in,line)){
        if(line.empty()) continue;
        std::stringstream ss(line);
        std::string id,user,hash,role;
        std::getline(ss,id,'|'); std::getline(ss,user,'|'); std::getline(ss,hash,'|'); std::getline(ss,role,'|');
        std::cout<<"User: "<<user<<" role="<<role<<" stored_hash="<<hash<<"\n";
    }
    // verify known creds
    auto check=[&](const std::string&u,const std::string&p){ std::hash<std::string>h; std::cout<<u<<":"<<h(p)<<"\n"; };
    std::cout<<"\nComputed hashes for sample passwords:\n";
    check("ta1","ta123");
    check("instr1","inst123");
    check("hod1","hod123");
    check("ao1","ao123");
    return 0;
}

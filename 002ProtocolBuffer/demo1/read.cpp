#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"
using namespace std;


void ListMsg(const lm::helloworld &msg){
   cout<<msg.id()<<endl;
   cout<<msg.str()<<endl;
}

int main(void){
    lm::helloworld msg1;
    fstream input("./log",ios::in | ios::binary);
    if(!msg1.ParseFromIstream(&input)){
        cerr<<"Failed to parse pb msg."<<endl;
        input.close();
        return -1;
    }
    input.close();
    ListMsg(msg1);
    return 0;
}

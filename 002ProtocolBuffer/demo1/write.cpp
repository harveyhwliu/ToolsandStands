#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"
using namespace std;

int main(void){
    lm::helloworld msg1;
    msg1.set_id(100);
    msg1.set_str("hello");

    //write into disck
    fstream output("./log", ios::out | ios::binary);
    if(!msg1.SerializeToOstream(&output)){
        cerr<<"Failed to write msg."<<endl;
        output.close();
        return -1;
    }
    output.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"
using namespace std;

int main(void){
    lm::person msg1;
    //msg1.set_name("harvey");  //这里先定义name 还是先定义id无区别
    msg1.set_id(1);
    msg1.set_name("harvey");
    msg1.set_email("2580205897@qq.com");
    
    //联系方式1   
    lm::person::PhoneNumber *phoneNumber = msg1.add_phone();
    phoneNumber->set_number("18888888888");
    phoneNumber->set_type(lm::person::MOBILE);
    
    //联系方式2
    phoneNumber = msg1.add_phone();
    phoneNumber->set_number("88888888");
    phoneNumber->set_type(lm::person::WORK);
    
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

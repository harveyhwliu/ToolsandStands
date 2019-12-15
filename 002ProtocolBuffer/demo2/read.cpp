#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"
using namespace std;


void ListMsg(const lm::person &msg){
   cout<<msg.id()<<endl;
   cout<<msg.name()<<endl;
   cout<<msg.id()<<endl;
   cout<<msg.email()<<endl;
   int phone_size = msg.phone_size();
   for(int i =0;i<phone_size;i++){
       lm::person::PhoneNumber phone = msg.phone(i);
       cout<<phone.number()<<endl;
       cout<<phone.type()<<endl;
   }
}

int main(void){
    lm::person msg1;
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

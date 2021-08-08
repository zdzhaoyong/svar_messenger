#include "Svar.h"

sv::Svar messenger=svar.import("svar_messenger")["messenger"];

int main(int argc,char** argv){

    auto sub= messenger.call("subscribe","example_topic",0,sv::Svar::lambda([](std::string msg){
        std::cout<<"Received "<<msg<<std::endl;
    }));

    messenger.call("publish","example_topic","hello world");
    auto pub=messenger.call("advertise","example_topic",0);

    pub.call("publish","hello publisher");

    std::cout<<messenger.call("introduction",80).as<std::string>()<<std::endl;
    return 0;
}

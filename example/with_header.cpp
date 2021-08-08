#include "Messenger.h"

void callback_int(int msg){
    std::cout<<"int:"<<msg<<std::endl;
}

void callback_json(sv::Svar json){
    std::cout<<"json:"<<json<<std::endl;
}

int main(int argc,char** argv){
    svar.parseMain(argc,argv);

    std::string topic=svar.arg<std::string>("topic","/example","Topic name");
    int         queue_size=svar.arg("queue",0,"Queue size, default sync call");

    auto sub_int=messenger.subscribe(topic,queue_size,callback_int);
    auto sub_json=messenger.subscribe(topic,queue_size,callback_json);

    messenger.publish(topic,-1);

    auto pub=messenger.advertise<int>(topic,0);
    for(int i=0;i<10;i++){
        pub.publish(i);
        usleep(1000000);
    }

    return 0;
}

# Messenger: Tiny Header-Only ROS like Pub-Sub Message Passing

This project is powered by [Svar](https://github.com/zdzhaoyong/Svar) and support multiple lanuages.

## Build and Install

```
mkdir build;cd build;cmake ..;sudo make install
```

## C++ Usages

### Simple Pub-Sub with Header

```
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

```

### Simple Pub-Sub without Header

```
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
```

## Python Usages

### Install Svar

```
pip3 install svar
```

### Simple Pub-Sub

```
import svar
import time

m = svar.load('svar_messenger')

def say(msg):
  print("received:",msg)

sub_no_thread = m.messenger.subscribe('example',0,say)
sub_new_thread = m.messenger.subscribe('example',1,say)

m.messenger.publish('example','hello world')

pub = m.messenger.advertise('example',1)

pub.publish({"is_json":True})

time.sleep(10)
```

## Differences against ROS Message Passing



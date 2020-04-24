#include "Messenger.h"

using namespace GSLAM;
using namespace sv;

REGISTER_SVAR_MODULE(messenger_){
    svar["__name__"]="messenger";
    svar["__doc__"] = "This is a tiny pubsub tool for languages";

    Class<Messenger>("Messenger")
                .construct<>()
                .def_static("instance",&Messenger::instance)
                .def("getPublishers",&Messenger::getPublishers)
                .def("getSubscribers",&Messenger::getSubscribers)
                .def("introduction",&Messenger::introduction)
                .def("advertise",[](Messenger msg,const std::string& topic,int queue_size){
          return msg.advertise<Svar>(topic,queue_size);
        })
        .def("subscribe",[](Messenger msger,
             const std::string& topic, int queue_size,
             const SvarFunction& callback){
          return msger.subscribe(topic,queue_size,callback);
        })
        .def("publish",[](Messenger* msger,std::string topic,Svar msg){return msger->publish(topic,msg);});

        Class<Publisher>("Publisher")
                .def("shutdown",&Publisher::shutdown)
                .def("getTopic",&Publisher::getTopic)
                .def("getTypeName",&Publisher::getTypeName)
                .def("getNumSubscribers",&Publisher::getNumSubscribers)
                .def("publish",[](Publisher* pubptr,Svar msg){return pubptr->publish(msg);});

        Class<Subscriber>("Subscriber")
                .def("shutdown",&Subscriber::shutdown)
                .def("getTopic",&Subscriber::getTopic)
                .def("getTypeName",&Subscriber::getTypeName)
                .def("getNumPublishers",&Subscriber::getNumPublishers);

      svar["messenger"]=Messenger::instance();
}

EXPORT_SVAR_INSTANCE

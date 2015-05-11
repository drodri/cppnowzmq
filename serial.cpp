#include "message.pb.h"
#include <string>
#include <iostream>


int main ()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
	tutorial::Person person;
    person.set_id(1234);
    person.set_name("john");
    person.set_email("john@mycompany.com");
    tutorial::Person::PhoneNumber* phone_number = person.add_phone();
    phone_number->set_number("1234567");
    phone_number->set_type(tutorial::Person::MOBILE);
    phone_number = person.add_phone();
    phone_number->set_number("7654321");
    phone_number->set_type(tutorial::Person::HOME);
    
    std::string msg_str;
    person.SerializeToString(&msg_str);
    std::cout<<msg_str;
   
    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
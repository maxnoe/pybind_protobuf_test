#include <pybind11/pybind11.h>
#include "Person.pb.h"
#include <string>
#include "pybind11_protobuf/native_proto_caster.h"

Person get_person() {
    Person person;
    person.set_id(1);
    person.set_name(std::string{"Maximilian Nöthe"});
    person.set_email(std::string{"maximilian.noethe@tu-dortmund.de"});
    return person;
}

PYBIND11_MODULE(fastproto, m) {
    pybind11_protobuf::ImportNativeProtoCasters();
    m.def("get_person", &get_person);
}

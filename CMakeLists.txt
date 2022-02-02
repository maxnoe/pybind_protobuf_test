cmake_minimum_required(VERSION 3.17..3.22)

project(Quirc++ VERSION 0.1.0 LANGUAGES C CXX)

include(GNUInstallDirs)

find_package(Python3 REQUIRED COMPONENTS Development Interpreter)
find_package(pybind11 REQUIRED)
find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS Person.proto)

pybind11_add_module(
    fastproto
    fastproto.cpp
    ${PROTO_SRCS}
    extern/pybind11_protobuf/pybind11_protobuf/native_proto_caster.cc
    extern/pybind11_protobuf/pybind11_protobuf/proto_cast_util.cc
    extern/pybind11_protobuf/pybind11_protobuf/proto_utils.cc
)
target_include_directories(fastproto PRIVATE ${CMAKE_CURRENT_BINARY_DIR} extern/pybind11_protobuf)
target_link_libraries(fastproto PRIVATE protobuf::libprotobuf)
target_compile_features(fastproto PRIVATE cxx_std_14)
set_target_properties(fastproto PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

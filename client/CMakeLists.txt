project(Client)

include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(libclient STATIC Network.h Network.cpp Client.cpp Client.h visuals/Dot.cpp visuals/Dot.h)

add_executable(client main.cpp)

target_link_libraries(client ${ENet_LIBRARIES} ${CONAN_LIBS} libclient)
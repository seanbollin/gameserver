project(Client)

include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(client STATIC Network.h Network.cpp Client.cpp Client.h visuals/Dot.cpp visuals/Dot.h)

add_executable(gameclient main.cpp)

target_link_libraries(gameclient ${ENet_LIBRARIES} ${CONAN_LIBS} libclient)
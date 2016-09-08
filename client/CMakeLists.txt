project(client)

include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(client STATIC Network.cpp Client.cpp visuals/Dot.cpp)

add_executable(gameclient main.cpp)

target_link_libraries(gameclient client ${ENet_LIBRARIES} ${CONAN_LIBS})
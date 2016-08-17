project(Client)

include(${PROJECT_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(client main.cpp Network.h Network.cpp Client.cpp Client.h)

target_link_libraries(client ${ENet_LIBRARIES} ${CONAN_LIBS})
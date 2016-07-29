project(Client)

add_executable(client main.cpp GameClient.cpp)

target_link_libraries(client ${ENet_LIBRARIES})
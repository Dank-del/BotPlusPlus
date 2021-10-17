cmake_minimum_required(VERSION 3.20.0)
project(BotPlusPlus VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -O3")
set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

include(FetchContent)

FetchContent_Declare(
    TgBot
    GIT_REPOSITORY https://github.com/reo7sp/tgbot-cpp.git
    GIT_TAG 814ac074633125c975fa6979e79c93cc7115a57b
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG 8826011c81b69e1f8427be520b357c19c74ea480
)

FetchContent_Declare(
    mdparser-cpp
    GIT_REPOSITORY https://github.com/ALiwoto/mdparser-cpp.git
    GIT_TAG caa8a8a78bfc14abf98a6183d12d3f0d02343542
)

FetchContent_Declare(
        toml11
        GIT_REPOSITORY https://github.com/ToruNiina/toml11.git
        GIT_TAG bcee9f25a22ab4d9a1211ddeab6b4da251c45adf
)

FetchContent_MakeAvailable(TgBot)
FetchContent_MakeAvailable(spdlog)
FetchContent_MakeAvailable(mdparser-cpp)
FetchContent_MakeAvailable(toml11)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} TgBot spdlog mdparser-cpp toml11)


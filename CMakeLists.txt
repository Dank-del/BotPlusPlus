cmake_minimum_required(VERSION 3.16.3)
project(BotPlusPlus VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Og -g")
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
    GIT_TAG a78b7b2aa498f20706069cec98b60be9a4bb6c05
)

FetchContent_Declare(
        toml11
        GIT_REPOSITORY https://github.com/ToruNiina/toml11.git
        GIT_TAG bcee9f25a22ab4d9a1211ddeab6b4da251c45adf
)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG b819f72baa86f452b93df5dd0f1c629df9c6c4a4
)

if (NOT EXISTS ${CMAKE_BINARY_DIR}/external/json/json.hpp)
	file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/external/json/)
	message(STATUS "Downloading nlohmann json...")
	file(DOWNLOAD "https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp" ${CMAKE_BINARY_DIR}/external/json/json.hpp SHOW_PROGRESS)
	message(STATUS "Download complete!")
endif (NOT EXISTS ${CMAKE_BINARY_DIR}/external/json/json.hpp)
set (JSON_INCLUDE_DIR ${CMAKE_BINARY_DIR}/external/json/)

include_directories(${JSON_INCLUDE_DIR})

FetchContent_MakeAvailable(TgBot)
FetchContent_MakeAvailable(spdlog)
FetchContent_MakeAvailable(mdparser-cpp)
FetchContent_MakeAvailable(toml11)
FetchContent_MakeAvailable(cpr)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE TgBot spdlog mdparser-cpp toml11 cpr::cpr)


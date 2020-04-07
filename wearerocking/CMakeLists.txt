CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_REQUIRED_STANDARD ON)
SET(CMAKE_DEBUG_POSTFIX "-d")

SET(PROJECT_NAME "wearerockingg")
PROJECT(${PROJECT_NAME} LANGUAGES CXX)

SET(HEADERS AppEngine.hpp AppSettings.hpp AppState.hpp Character.hpp CharacterCreateState.hpp CharacterEditState.hpp CharacterListState.hpp CharacterViewState.hpp Globals.hpp MainMenuState.hpp SettingsParser.hpp)
SET(SOURCES AppEngine.cpp Character.cpp CharacterCreateState.cpp CharacterEditState.cpp CharacterListState.cpp CharacterViewState.cpp main.cpp MainMenuState.cpp SettingsParser.cpp)
ADD_EXECUTABLE(${PROJECT_NAME} ${HEADERS} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ../SFML/include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window sfml-system -L"../SFML/lib")

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ../../SFUI/include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} sfui -L"../../SFUI/lib")

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ../../SFWS/include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} sfws -L"../../SFWS/lib")

TARGET_LINK_LIBRARIES(${PROJECT_NAME} stdc++fs)

project(Doodlejump_Said_Yandarbiev)
cmake_minimum_required(VERSION 3.10.2)


###################### SFML ######################
if(APPLE)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1-MAC/include")
    set( SFML_LIBRARY_DIR "libs/SFML-2.5.1-MAC/build/lib")

elseif (UNIX)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/include/")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/cmake/SFML/")
    set(SFML_SHARE "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/share/")

elseif(WIN32)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/include/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/lib/cmake/SFML")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/lib/")
    file(GLOB SFML_DLL "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/bin/*.dll")
    file(COPY ${SFML_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

endif()

link_directories(SFML_LIBRARY_DIR )
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Doodlejump_Said_Yandarbiev main.cpp
        Src/sd/Observer.cpp
        Src/sd/Observer.h
        Src/sd/Score.cpp
        Src/sd/Score.h
        Src/sd/Subject.h
        Src/sd/Subject.cpp
        Src/sd/Entity_Model.cpp
        Src/sd/Entity_Model.h
        Src/sd/Player.h
        Src/sd/Player.cpp
        Src/sd/Platform.h
        Src/sd/Platform.cpp
        Src/sd/BG_Tile.h
        Src/sd/BG_Tile.cpp
        Src/sd/Bonus.h
        Src/sd/Bonus.cpp
        Src/sd/Random.cpp
        Src/sd/Random.h
        Src/sd/Camera.cpp
        Src/sd/Camera.h
        Src/sd/Stopwatch.cpp
        Src/sd/Stopwatch.h
        Src/sd/World.cpp
        Src/sd/World.h
        Src/sd/Abstract_Factory.cpp
        Src/sd/Abstract_Factory.h
        Src/Game_Representation/Entity_view.cpp
        Src/Game_Representation/Entity_view.h
        Src/Game_Representation/Player.cpp
        Src/Game_Representation/Player.h
        Src/Game_Representation/Platform.cpp
        Src/Game_Representation/Platform.h
        Src/Game_Representation/BG_Tile.cpp
        Src/Game_Representation/BG_Tile.h
        Src/Game_Representation/Bonus.cpp
        Src/Game_Representation/Bonus.h
        Src/Game_Representation/Game.cpp
        Src/Game_Representation/Game.h)
target_link_libraries(Doodlejump_Said_Yandarbiev
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system)
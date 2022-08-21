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

add_executable(Doodlejump_Said_Yandarbiev
        Src/main.cpp
        Src/Vector2.h
        Src/Vector2.cpp
        Src/window.h
        Src/window.cpp
        Src/Logic/Observer.cpp
        Src/Logic/Observer.h
        Src/Game_Representation/Entity_view.cpp
        Src/Game_Representation/Entity_view.h
        Src/Game_Representation/Player_View.cpp
        Src/Game_Representation/Player_View.h
        Src/Game_Representation/Platform_View.cpp
        Src/Game_Representation/Platform_View.h
        Src/Game_Representation/BG_Tile_View.cpp
        Src/Game_Representation/BG_Tile_View.h
        Src/Game_Representation/Bonus_View.cpp
        Src/Game_Representation/Bonus_View.h
        Src/Game_Representation/Game.cpp
        Src/Game_Representation/Game.h
        Src/Game_Representation/Concrete_Factory.h
        Src/Game_Representation/Concrete_Factory.cpp
        Src/Game_Representation/Complex_Enemy_View.cpp
        Src/Game_Representation/Complex_Enemy_View.h
        Src/Game_Representation/Simple_Enemy_View.cpp
        Src/Game_Representation/Simple_Enemy_View.h
        Src/Game_Representation/Ball_View.cpp
        Src/Game_Representation/Ball_View.h
        Src/Logic/Score.cpp
        Src/Logic/Score.h
        Src/Logic/Subject.h
        Src/Logic/Subject.cpp
        Src/Logic/Entity_Model.cpp
        Src/Logic/Entity_Model.h
        Src/Logic/Player_Model.h
        Src/Logic/Player_Model.cpp
        Src/Logic/Platform_Model.h
        Src/Logic/Platform_Model.cpp
        Src/Logic/BG_Tile_Model.h
        Src/Logic/BG_Tile_Model.cpp
        Src/Logic/Bonus_Model.h
        Src/Logic/Bonus_Model.cpp
        Src/Logic/Random.cpp
        Src/Logic/Random.h
        Src/Logic/Camera.cpp
        Src/Logic/Camera.h
        Src/Logic/Stopwatch.cpp
        Src/Logic/Stopwatch.h
        Src/Logic/World.cpp
        Src/Logic/World.h
        Src/Logic/Abstract_Factory.cpp
        Src/Logic/Abstract_Factory.h
        Src/Logic/States.h
        Src/Logic/States.cpp
        Src/Logic/Complex_Enemy_Model.cpp
        Src/Logic/Complex_Enemy_Model.h
        Src/Logic/Enemy_Model.cpp
        Src/Logic/Enemy_Model.h
        Src/Logic/Simple_Enemy_Model.cpp
        Src/Logic/Simple_Enemy_Model.h
        Src/Logic/Hp.h
        Src/Logic/Hp.cpp
        Src/Logic/Ball_Model.cpp
        Src/Logic/Ball_Model.h
        )

target_link_libraries(Doodlejump_Said_Yandarbiev
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system)
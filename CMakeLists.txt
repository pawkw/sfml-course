cmake_minimum_required(VERSION 2.6)
project("Pac-Woman")

add_definitions("-std=c++11")

set(SRC src/main.cpp
        src/Game.cpp
        src/GameState.cpp
        src/entities/Dot.cpp
        src/entities/Bonus.cpp
        src/entities/Character.cpp
        src/entities/Pacwoman.cpp
        src/entities/Ghost.cpp
)

add_executable(pacwoman ${SRC})

target_link_libraries( pacwoman sfml-system)
target_link_libraries( pacwoman sfml-window)
target_link_libraries( pacwoman sfml-graphics)
target_link_libraries( pacwoman sfml-audio)
target_link_libraries( pacwoman sfml-network)

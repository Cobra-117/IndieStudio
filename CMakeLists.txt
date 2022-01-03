project(bomberman)
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
FIND_PACKAGE(raylib 3.7)

set(SRCS
        src/Engine/Texture/Images.cpp
        src/Engine/Texture/Textures.cpp
        src/Engine/Audio/AudioManager.cpp
        src/Engine/Audio/Music.cpp
        src/Engine/Audio/AudioStream.cpp
        src/Engine/Audio/Sound.cpp
        src/Engine/Text/Text.cpp
        src/Engine/Core/Core.cpp
        src/Engine/Core/Window.cpp
        src/Engine/Core/Cursor.cpp
        src/Engine/Core/Drawer.cpp
        src/Engine/Core/InputKey.cpp
        src/Engine/Core/InputMouse.cpp
        src/Engine/Core/Misc.cpp
        src/Engine/Core/FileManager.cpp
        src/Game/Map.cpp
        src/Game/Tools/Utilities.cpp
        src/Game/Menu/MenuWindow.cpp
        src/Engine/Shapes/Circle.cpp
        src/Engine/Shapes/Rectangle.cpp
        src/Engine/Shapes/Triangle.cpp
        src/Engine/Shapes/Polygone.cpp
        src/Engine/Shapes/Ring.cpp
        src/Engine/Shapes/Ellipse.cpp
        src/Engine/Shapes/Line.cpp
        src/Engine/Shapes/CollisionChecker.cpp
        src/Game/Game.cpp
        src/Game/Events.cpp
        src/Game/Menu/MenuLoadSave.cpp
        src/Game/Menu/MenuSettings.cpp
        src/Engine/Models/models.cpp
        src/Game/Player.cpp
        src/Game/AIPlayer.cpp
        src/Game/Tools/DirectoryReader.cpp
        src/Game/Bombs/Bomb.cpp
        src/Game/Menu/MenuScreenShot.cpp
        src/Engine/Models/models.cpp
        src/Game/Menu/PlayerChoice.cpp
        src/Game/Menu/Credits.cpp
        src/Engine/Colliders/SquareCollider.cpp
        src/Game/Menu/EndGame.cpp
        src/Game/Powerup/Powerup.cpp
    )

set(HEADERS
        tests/Test.hpp
        include/indie.hpp
        include/Engine/Audio/AudioStream.hpp
        include/Engine/Audio/AudioManager.hpp
        include/Engine/Audio/Sound.hpp
        include/Engine/Audio/Music.hpp
        include/Engine/Textures/Textures.hpp
        include/Engine/Textures/Images.hpp
        include/Engine/Text/Text.hpp
        include/Engine/Core/Core.hpp
        include/Engine/Core/Window.hpp
        include/Engine/Core/Cursor.hpp
        include/Engine/Core/Drawer.hpp
        include/Engine/Core/InputKey.hpp
        include/Engine/Core/InputMouse.hpp
        include/Engine/Core/Misc.hpp
        include/Game/Menu/MainMenu.hpp
        include/Game/Menu/Settings.hpp
        include/Game/Map.hpp
        include/Engine/Shapes/Circle.hpp
        include/Engine/Shapes/CollisionChecker.hpp
        include/Engine/Shapes/Ellipse.hpp
        include/Engine/Shapes/Line.hpp
        include/Engine/Shapes/Polygone.hpp
        include/Engine/Shapes/Rectangle.hpp
        include/Engine/Shapes/Ring.hpp
        include/Engine/Shapes/Triangle.hpp
        include/Game/Game.hpp
        include/Game/Player.hpp
        include/Game/Bombs/bomb.hpp
        include/Game/Tools/Utilities.hpp
        include/Game/Tools/DirectoryReader.hpp
        include/Game/Bombs/bomb.hpp
        include/Game/Menu/GameButton.hpp
        include/Game/Menu/ScreenShot.hpp
        include/Game/Menu/PlayerChoice.hpp
        include/Game/Menu/BoxText.hpp
        include/Game/Menu/Credits.hpp
        include/Engine/Colliders/SquareCollider.hpp
        include/Game/Menu/EndGame.hpp
        include/Game/Powerup/Powerup.hpp
    )

ENABLE_TESTING()
add_executable(bomberman src/main.cpp ${SRCS} ${HEADERS})
add_executable(test_bomberman tests/Test.cpp ${SRCS} ${HEADERS})
ADD_TEST(            testing_bomberman test_bomberman    )
TARGET_LINK_LIBRARIES(bomberman raylib)
TARGET_LINK_LIBRARIES(test_bomberman raylib)

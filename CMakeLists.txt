cmake_minimum_required(VERSION 3.10)

project(littleray)

# SDL2 dependency
find_path(SDL2_INCLUDE_DIR NAMES SDL2/SDL.h)
find_library(SDL2_LIBRARY NAMES SDL2)

# Main executable
add_executable(littleray raytracer.cpp
    Context.cpp
    ContextFactory.cpp
    Pixel.cpp
    Scene.cpp
    SceneFactory.cpp
    Materials/BlinnProperty.cpp
    Materials/MaterialPropertyFactory.cpp
    Materials/LambertProperty.cpp
    Materials/MaterialFactory.cpp
    Materials/Material.cpp
    Materials/PhongProperty.cpp
    Displays/FakeDisplay.cpp
    Displays/DisplayFactory.cpp
    Displays/SDLDisplay.cpp
    Objects/ObjectFactory.cpp
    Objects/SphereFactory.cpp
    Objects/Sphere.cpp
    Antialiasers/Supersampler4x.cpp
    Antialiasers/Supersampler16x.cpp
    Antialiasers/AntialiaserFactory.cpp
    Antialiasers/FakeAntialiaser.cpp
    Xml/tinystr.cpp
    Xml/tinyxmlparser.cpp
    Xml/tinyxmlerror.cpp
    Xml/tinyxml.cpp
    Maths/Vector.cpp
    Maths/Point.cpp
    Lights/LightFactory.cpp
    Lights/Light.cpp
    Lights/Ray.cpp)

target_include_directories(littleray PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIR})
target_link_libraries(littleray ${SDL2_LIBRARY})


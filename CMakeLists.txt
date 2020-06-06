cmake_minimum_required(VERSION 3.10)

project(littleray)

# SDL dependency
find_path(SDL_INCLUDE_DIR NAMES SDL/SDL.h)
find_library(SDL_LIBRARY NAMES SDL)

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

target_include_directories(littleray PUBLIC ${PROJECT_SOURCE_DIR} ${SDL_INCLUDE_DIR})
target_link_libraries(littleray ${SDL_LIBRARY})


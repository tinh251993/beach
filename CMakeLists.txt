cmake_minimum_required (VERSION 3.0)
project (irrlicht)


find_package(OpenGL)
find_package(X11)
find_package(ZLIB)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(
   "/usr/include/irrlicht"
  ${PROJECT_SOURCE_DIR}/include
  ${X11_INCLUDE_DIR}
  ${GLUT_INCLUDE_DIR}
  ${ZLIB_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
)


add_executable (
    exam1
    
    main.cpp
    
)



target_link_libraries(
    exam1

    
    "/home/change2520/irrlicht-1.8.4/lib/Linux/libIrrlicht.a"
    ${X11_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
    ${ZLIB_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    -lGL -lX11 -lXrandr -lXxf86vm  -lrt -lm -pthread -lm -lGLU
)
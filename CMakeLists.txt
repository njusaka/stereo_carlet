CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_BUILD_TYPE RELEASE)

include_directories(
    /usr/local/include
    /usr/include/
)

add_executable(stereo
    main.cpp
    light_tracking.cpp
)

target_link_libraries(stereo
    opencv_core
    opencv_video
    opencv_highgui
    opencv_imgproc

    wiringPi
)

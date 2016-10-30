cmake_minimum_required(VERSION 2.8)
project( Look_At_My_Eyes)
find_package( OpenCV REQUIRED )
find_package(Threads)
add_executable( Look_At_My_Eyes main.cpp DCMotor.cpp sserial.cpp Image_Process.cpp findEyeCenter.cpp findEyeCorner.cpp helpers.cpp)
target_link_libraries( Look_At_My_Eyes /usr/local/lib/libwiringPi.so /usr/local/lib/libwiringPiDev.so ${OpenCV_LIBS} )

INCLUDE_DIRECTORIES(/home/pi/Look_At_My_Eyes)

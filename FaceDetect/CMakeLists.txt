cmake_minimum_required(VERSION 2.8)
project(FaceDetect)
find_package( OpenCV REQUIRED )
add_executable( facedetect facedetect.cpp )
target_link_libraries( facedetect ${OpenCV_LIBS} )


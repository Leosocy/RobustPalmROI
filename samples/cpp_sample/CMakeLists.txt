CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(PROJECT_NAME run_cpp_sample)
PROJECT(${PROJECT_NAME})
SET(SAMPLES_ROOT ${CMAKE_BINARY_DIR}/../..)

ADD_DEFINITIONS(-std=c++11)

FIND_PACKAGE(robust-palm-roi REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(${ROBUST_PALM_ROI_INCLUDE_DIR})

EXECUTE_PROCESS(COMMAND ${SAMPLES_ROOT}/palm_data/download.sh)

ADD_EXECUTABLE(${PROJECT_NAME} sample.cpp)

ADD_DEPENDENCIES(${PROJECT_NAME} ${ROBUST_PALM_ROI_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ROBUST_PALM_ROI_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS} )

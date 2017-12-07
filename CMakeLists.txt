cmake_minimum_required(VERSION 3.7)
project(impulse_ml_dataset)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/src/Impulse/Dataset/common.h
        src/src/Impulse/Dataset/common.cpp
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.cpp
        src/src/Impulse/Dataset/DatasetBuilder/Abstract.h
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.cpp
        src/src/Impulse/Dataset/DatasetBuilder/CSVBuilder.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Callback.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Category.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/CategoryId.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MinMaxScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/MissingData.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/ZScoresScaling.h
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.cpp
        src/src/Impulse/Dataset/DatasetModifier/Modifier/Abstract.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSlicer.h
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.cpp
        src/src/Impulse/Dataset/DatasetModifier/DatasetSplitter.h
        src/src/Impulse/Dataset/Dataset.cpp
        src/src/Impulse/Dataset/Dataset.h
        src/src/Impulse/Dataset/DatasetSample.cpp
        src/src/Impulse/Dataset/DatasetSample.h
        src/main.cpp
        src/src/Impulse/Dataset/include.h src/src/Impulse/Dataset/DatasetExporter/Abstract.h src/src/Impulse/Dataset/DatasetExporter/Abstract.cpp src/src/Impulse/Dataset/DatasetExporter/CSVExporter.h src/src/Impulse/Dataset/DatasetExporter/CSVExporter.cpp)

# OpenMP
# -fopenmp
FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif ()

# boost
# -lboost_system -lboost_filesystem
#[[find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
if (BOOST_FOUND)
    message("Boost FOUND")
    include_directories(${Boost_INCLUDE_DIRS})
endif ()]]

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(impulse_ml_dataset ${SOURCE_FILES})

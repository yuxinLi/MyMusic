
cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/include)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             
             src/main/cpp/native-lib.cpp
             src/main/cpp/WlAudio.cpp
             src/main/cpp/WlCallJava.cpp
             src/main/cpp/WlFFmpeg.cpp
             src/main/cpp/WlPlayStatus.cpp
             src/main/cpp/WlQueue.cpp)


# ----------- FFmpeg begin ---------
add_library( avcodec SHARED IMPORTED)
set_target_properties( avcodec
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavcodec.so)

add_library( avdevice SHARED IMPORTED)
set_target_properties( avdevice
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavdevice.so)

add_library( avfilter SHARED IMPORTED)
set_target_properties( avfilter
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavfilter.so)

add_library( avformat SHARED IMPORTED)
set_target_properties( avformat
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavformat.so)

add_library( avutil SHARED IMPORTED)
set_target_properties( avutil
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavutil.so)

add_library( swresample SHARED IMPORTED)
set_target_properties( swresample
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libswresample.so)

add_library( swscale SHARED IMPORTED)
set_target_properties( swscale
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libswscale.so)


# ----------- FFmpeg end ---------



target_link_libraries( # Specifies the target library.
                       native-lib

                       #----- FFmpeg begin ----
                       avcodec
                       avdevice
                       avfilter
                       avformat
                       avutil
                       swresample
                       swscale
                       #----- FFmpeg end ----


                       # Links the target library to the log library
                       # included in the NDK.
                       log )
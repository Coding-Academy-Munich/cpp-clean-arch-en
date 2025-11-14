# On some Linux systems shm_unlink is provided by librt. Create a small
# INTERFACE target that links librt on Unix (Linux) and is a no-op on
# Windows/macOS. Link this `posix_rt` target into all executables below.
set(RT_LIB "")
if(UNIX AND NOT APPLE)
        # Prefer an absolute library if available, otherwise fall back to the name 'rt'
        find_library(_RT_LIB rt)
        if(_RT_LIB)
                set(RT_LIB ${_RT_LIB})
        else()
                set(RT_LIB rt)
        endif()
endif()

add_library(posix_rt INTERFACE)
if(RT_LIB)
        target_link_libraries(posix_rt INTERFACE ${RT_LIB})
endif()

# Pthread functions are needed on Unix systems. Use CMake's Threads package.
find_package(Threads REQUIRED)

add_library(posix_pthread INTERFACE)
target_link_libraries(posix_pthread INTERFACE Threads::Threads)

add_executable(shm_010_starter
                shm_010_starter.cpp
                shm_010_starter.h
                utils.h)
target_link_libraries(shm_010_starter Boost::interprocess posix_rt posix_pthread)

add_executable(shm_020_mapped_region
        shm_020_mapped_region.cpp
        shm_020_mapped_region.h
        utils.h)
target_link_libraries(shm_020_mapped_region Boost::interprocess posix_rt posix_pthread)

add_executable(shm_025_mapped_region_multi
        shm_025_mapped_region_multi.cpp
        shm_025_mapped_region_multi.h
        utils.h)
target_link_libraries(shm_025_mapped_region_multi Boost::interprocess posix_rt posix_pthread)

add_executable(shm_030_managed_segment
        shm_030_managed_segment.cpp
        shm_030_managed_segment.h
        utils.h)
target_link_libraries(shm_030_managed_segment Boost::interprocess posix_rt posix_pthread)

add_executable(shm_035_managed_segment_multi
        shm_035_managed_segment_multi.cpp
        shm_035_managed_segment_multi.h
        utils.h)
target_link_libraries(shm_035_managed_segment_multi Boost::interprocess posix_rt posix_pthread)

add_executable(shm_040_named_objects
        shm_040_named_objects.cpp
        shm_040_named_objects.h
        utils.h)
target_link_libraries(shm_040_named_objects Boost::interprocess posix_rt posix_pthread)

add_executable(shm_050_bad_pointer
        shm_050_bad_pointer.cpp
        shm_050_bad_pointer.h
        utils.h)
target_link_libraries(shm_050_bad_pointer Boost::interprocess posix_rt posix_pthread)

add_executable(shm_060_offset_pointer
        shm_060_offset_pointer.cpp
        shm_060_offset_pointer.h
        utils.h)
target_link_libraries(shm_060_offset_pointer Boost::interprocess posix_rt posix_pthread)

add_executable(shm_070_allocator
        shm_070_allocator.cpp
        shm_070_allocator.h
        utils.h)
target_link_libraries(shm_070_allocator Boost::interprocess posix_rt posix_pthread)

add_executable(shm_080_producer
        shm_080_producer.cpp
        shm_080_queue.h)
target_link_libraries(shm_080_producer Boost::interprocess posix_rt posix_pthread)

add_executable(shm_080_consumer
        shm_080_consumer.cpp
        shm_080_queue.h)
target_link_libraries(shm_080_consumer Boost::interprocess posix_rt posix_pthread)

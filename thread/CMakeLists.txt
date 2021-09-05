add_executable(thread_demo thread_demo.cpp)

add_executable(thread_mutex1 thread_mutex1.cpp)
add_executable(thread_mutex2 thread_mutex2.cpp)
add_executable(thread_mutex3 thread_mutex3.cpp)

add_executable(thread_condition1 thread_condition1.cpp)
add_executable(thread_condition2 thread_condition2.cpp)
add_executable(thread_condition3 thread_condition3.cpp)

add_executable(thread_atomic1 thread_atomic1.cpp)
add_executable(thread_atomic2 thread_atomic2.cpp)
add_executable(thread_atomic3 thread_atomic3.cpp)

set_target_properties(thread_demo PROPERTIES FOLDER "thread")

set_target_properties(thread_mutex1 PROPERTIES FOLDER "thread")
set_target_properties(thread_mutex2 PROPERTIES FOLDER "thread")
set_target_properties(thread_mutex3 PROPERTIES FOLDER "thread")

set_target_properties(thread_condition1 PROPERTIES FOLDER "thread")
set_target_properties(thread_condition2 PROPERTIES FOLDER "thread")
set_target_properties(thread_condition3 PROPERTIES FOLDER "thread")

set_target_properties(thread_atomic1 PROPERTIES FOLDER "thread")
set_target_properties(thread_atomic2 PROPERTIES FOLDER "thread")
set_target_properties(thread_atomic3 PROPERTIES FOLDER "thread")


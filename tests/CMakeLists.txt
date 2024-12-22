project(rmgr-nsfr-tests CXX)

add_executable(rmgr-nsfr-tests "tests.cpp")

target_link_libraries(rmgr-nsfr-tests rmgr-nsfr)
target_compile_options(rmgr-nsfr-tests PRIVATE ${RMGR_NSFR_COMPILE_OPTIONS})
target_compile_features(rmgr-nsfr-tests PRIVATE cxx_std_11)

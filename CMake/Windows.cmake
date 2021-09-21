if (MSVC)
    #    message("\n\n\n\nWTF\n\n\n\n")
    #    # disable autolinking in boost
    #    add_definitions( -DBOOST_ALL_NO_LIB )
    #
    #    # force all boost libraries to dynamic link (we already disabled
    #    # autolinking, so I don't know why we need this, but we do!)
    #    add_definitions( -DBOOST_ALL_DYN_LINK )
    ####### Dependency Directories ##########
    set(DEP_INCLUDE C:\\Users\\Tyler\\OneDrive\\Desktop\\workspace\\SiphonDB\\SiphonWorkerDependencies\\.build\\boost_1_71_0)
    set(DEP_LINK C:\\Users\\Tyler\\OneDrive\\Desktop\\workspace\\SiphonDB\\SiphonWorkerDependencies\\.build\\boost_1_71_0\\stage\\lib)


    set (LIBRARY_PREFIX lib)
    set (LIBRARY_SUFFIX -vc142-mt-gd-x64-1_71)
    ####### Boost Libraries ##########
    set(LIB_BOOST_SERIALIZATION ${LIBRARY_PREFIX}boost_serialization${LIBRARY_SUFFIX})
    set(LIB_BOOST_PYTHON ${LIBRARY_PREFIX}boost_python38${LIBRARY_SUFFIX})


    if (WIN32)
        # Prefix all shared libraries with 'lib'.
        set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
        # Prefix all static libraries with 'lib'.
        set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
    endif()
endif()

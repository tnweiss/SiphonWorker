if (MSVC)
    ####### Warnings ##########
    # Disables
    #    warning C4996: 'sprintf': This function or variable may be unsafe. Consider using sprintf_s instead.
    #    To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS )


    ####### Lib Definitions ##########
    # library prefix and suffixes
    set (LP lib)
    set (LS -vc142-mt-gd-x64-1_71.lib)
    set (LIB_DIR ${CMAKE_SOURCE_DIR}/dependencies/lib)


    ####### Boost Libraries ##########
    set(LIB_BOOST_SERIALIZATION ${LIB_DIR}/${LP}boost_serialization${LS})
    set(LIB_BOOST_PYTHON        ${LIB_DIR}/${LP}boost_python38${LS})
endif()

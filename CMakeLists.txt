cmake_minimum_required(VERSION 3.5)

project(SecretMessagingFrontEnd VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        CreateSecretWidget.h
        CreateSecretWidget.cpp
        Encoder.h
        Encoder.cpp
        RevealSecretWidget.h
        RevealSecretWidget.cpp
        resources.qrc
        MainTabWidget.h MainTabWidget.cpp
)

qt6_add_resources(resources.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SecretMessagingFrontEnd
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SecretMessagingFrontEnd APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SecretMessagingFrontEnd SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SecretMessagingFrontEnd
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SecretMessagingFrontEnd PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Enable for WASM optimisations
# target_compile_options(SecretMessagingFrontEnd PRIVATE -oz -flto)
# target_link_options(SecretMessagingFrontEnd PRIVATE -flto)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SecretMessagingFrontEnd)
endif()
set_target_properties(SecretMessagingFrontEnd PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SecretMessagingFrontEnd
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SecretMessagingFrontEnd)
endif()

# Add tests
qt_add_executable(Tests
    MANUAL_FINALIZATION
    Tests.cpp Encoder.h Encoder.cpp
    )

qt_finalize_executable(Tests)

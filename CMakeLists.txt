cmake_minimum_required(VERSION 3.18)
project(dolphin-owncloud)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

include(FeatureSummary)

set(QT_MIN_VERSION 6.5.0)
set(KF6_MIN_VERSION 6.1.0)
set(ECM_MIN_VERSION 6.0.0)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(QT ${QT_MIN_VERSION} NAMES Qt6 COMPONENTS Gui Core Network REQUIRED)

message(STATUS "Using Qt ${QT_VERSION}")

find_package(ECM ${ECM_MIN_VERSION} REQUIRED CONFIG)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS CoreAddons KIO Bookmarks)

set_package_properties(DolphinVcs PROPERTIES
    DESCRIPTION "the Dolphin plugin library"
    URL "http://dolphin.kde.org/"
    TYPE REQUIRED
    PURPOSE "Provides plugin interfaces for Dolphin."
)

set(KDE_INSTALL_DIRS_NO_DEPRECATED TRUE)
include(KDEInstallDirs)
# kcoreaddons_add_plugin uses deprecated VAR PLUGIN_INSTALL_DIR
# when that is fixed and you want to remove this workaround,
# you need to _require_ the new enough kcoreaddons
set(PLUGIN_INSTALL_DIR "${KDE_INSTALL_PLUGINDIR}")
include(ECMMarkNonGuiExecutable)
include(ECMSetupVersion)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMMarkNonGuiExecutable)
include(GenerateExportHeader)

set(APPLICATION_NAME       "ownCloud" CACHE STRING "Branding parameter")
set(APPLICATION_SHORTNAME  "ownCloud" CACHE STRING "Branding parameter")
set(APPLICATION_EXECUTABLE "owncloud" CACHE STRING "Branding parameter")

add_subdirectory(src)

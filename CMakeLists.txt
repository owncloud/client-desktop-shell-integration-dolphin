cmake_minimum_required(VERSION 3.18)
project(owncloud-client-shell-integration-dolphin VERSION 6.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

include(FeatureSummary)

set(QT_MIN_VERSION 6.5.0)
set(KF6_MIN_VERSION 6.1.0)
set(ECM_MIN_VERSION 6.0.0)

option(REQUIRE_OWNCLOUD_RESOURCES "We depend on the ownCloud resources, if your distribution does provide alternative icons you can disable this requirement" ON)


set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(QT ${QT_MIN_VERSION} NAMES Qt6 COMPONENTS Gui Core Network REQUIRED)

message(STATUS "Using Qt ${QT_VERSION}")

find_package(ECM ${ECM_MIN_VERSION} REQUIRED CONFIG)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS CoreAddons KIO Bookmarks)

if (REQUIRE_OWNCLOUD_RESOURCES)
    find_package(ownCloudShellResources 1.0.0 REQUIRED)
    set_package_properties(ownCloudShellResources PROPERTIES TYPE REQUIRED DESCRIPTION "Required ownCloud resources and icons" URL "https://github.com/owncloud/client-desktop-shell-integration-resources")
endif()


include(KDEInstallDirs)
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

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

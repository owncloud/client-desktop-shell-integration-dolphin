project(dolphin-owncloud)

cmake_minimum_required(VERSION 3.16)

include(FeatureSummary)

set(QT_MIN_VERSION "5.9.7")
set(KF5_MIN_VERSION "5.52.0")

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Core Network)

find_package(ECM ${KF5_MIN_VERSION} REQUIRED CONFIG)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS CoreAddons KIO)

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
include(KDECMakeSettings)
include(KDECompilerSettings)
include(ECMMarkNonGuiExecutable)
include(GenerateExportHeader)

if(NOT DEFINED APPLICATION_EXECUTABLE)
  set(APPLICATION_EXECUTABLE "owncloud")
endif()

add_subdirectory(src)

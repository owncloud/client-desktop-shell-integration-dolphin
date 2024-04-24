#---HELPER---
set(OWNCLOUDDOLPHINHELPER ${APPLICATION_EXECUTABLE}dolphinpluginhelper)
add_library(${OWNCLOUDDOLPHINHELPER} SHARED ownclouddolphinpluginhelper.cpp ownclouddolphinpluginhelper.h)
generate_export_header(${OWNCLOUDDOLPHINHELPER} BASE_NAME ownclouddolphinpluginhelper)
target_link_libraries(${OWNCLOUDDOLPHINHELPER} Qt6::Core Qt6::Network Qt6::Gui)
target_compile_definitions(${OWNCLOUDDOLPHINHELPER} PRIVATE QT_USE_QSTRINGBUILDER APPLICATION_SHORTNAME="${APPLICATION_SHORTNAME}")

install(TARGETS ${OWNCLOUDDOLPHINHELPER} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

#---OVERLAY PLUGIN---
set(OWNCLOUDDOLPHINOVERLAYPLUGIN ${APPLICATION_EXECUTABLE}dolphinoverlayplugin)
kcoreaddons_add_plugin(${OWNCLOUDDOLPHINOVERLAYPLUGIN} INSTALL_NAMESPACE "kf6/overlayicon"
                       SOURCES ownclouddolphinoverlayplugin.cpp)
target_link_libraries(${OWNCLOUDDOLPHINOVERLAYPLUGIN} KF6::CoreAddons KF6::KIOCore KF6::KIOWidgets ${OWNCLOUDDOLPHINHELPER})

#---ACTION PLUGIN---
set(OWNCLOUDDOLPHINACTIONPLUGIN ${APPLICATION_EXECUTABLE}dolphinactionplugin)
configure_file(ownclouddolphinactionplugin.json.in ${OWNCLOUDDOLPHINACTIONPLUGIN}.json ESCAPE_QUOTES @ONLY)
kcoreaddons_add_plugin(${OWNCLOUDDOLPHINACTIONPLUGIN} SOURCES ownclouddolphinactionplugin.cpp INSTALL_NAMESPACE "kf6/kfileitemaction")

target_sources(ownclouddolphinactionplugin
  PRIVATE
    ownclouddolphinactionplugin.h
)
target_link_libraries(${OWNCLOUDDOLPHINACTIONPLUGIN} KF6::CoreAddons KF6::KIOCore KF6::KIOWidgets ${OWNCLOUDDOLPHINHELPER})

# FIXME: Install target wrong
# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${OWNCLOUDDOLPHINACTIONPLUGIN}.json DESTINATION ${KDE_INSTALL_PLUGINDIR})
install(TARGETS ${OWNCLOUDDOLPHINACTIONPLUGIN} DESTINATION ${KDE_INSTALL_PLUGINDIR})

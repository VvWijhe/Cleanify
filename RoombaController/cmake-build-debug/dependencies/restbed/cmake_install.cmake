# Install script for directory: /home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/restbed")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include" TYPE FILE FILES "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/restbed")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/uri.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/byte.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/http.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/rule.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/common.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/string.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/logger.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/request.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/service.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/session.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/settings.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/response.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/resource.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/web_socket.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/status_code.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/ssl_settings.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/context_value.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/session_manager.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/web_socket_message.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/context_placeholder.hpp;/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed/context_placeholder_base.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/distribution/include/corvusoft/restbed" TYPE FILE FILES
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/uri.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/byte.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/http.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/rule.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/common.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/string.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/logger.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/request.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/service.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/session.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/settings.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/response.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/resource.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/web_socket.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/status_code.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/ssl_settings.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/context_value.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/session_manager.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/web_socket_message.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/context_placeholder.hpp"
    "/home/bas/CLionProjects/Cleanify/RoombaController/dependencies/restbed/source/corvusoft/restbed/context_placeholder_base.hpp"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "library" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/library" TYPE STATIC_LIBRARY FILES "/home/bas/CLionProjects/Cleanify/RoombaController/cmake-build-debug/dependencies/restbed/librestbed.a")
endif()


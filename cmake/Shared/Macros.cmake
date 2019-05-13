# Copyright (c) 2019 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

#
# Shared macros.
#

# Check if loaded via FindBootstrap.cmake module.
macro(check_bootstrap_step)
	if(NOT DEFINED _ROOT_PATH_REQUIRED OR NOT DEFINED _CMAKE_MODULE_PATH_REQUIRED)
	  message(FATAL_ERROR "Use find_package(Bootstrap REQUIRED) to load this file.")
	endif()
endmacro()

# Add external project dependency.
macro(enqueue_external_dependency)
	# Directories.
	set(_TMP_DIR 		"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/temp")
	set(_STAMP_DIR 		"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/stamp")
	set(_DOWNLOAD_DIR	"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/fetched")
	set(_SOURCE_DIR 	"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/src")
	set(_BINARY_DIR 	"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/build")
	set(_INSTALL_DIR 	"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/install")
	set(_LOG_DIR 		"${THIRD_PARTY_LIBS_PATH}/${LIBRARY_NAME}/logs")
	
	# Arguments.
	set(_CMAKE_ARGS		"-DCMAKE_INSTALL_PREFIX=${_INSTALL_DIR}")
	
	# Enqueue library for download, build & install.
	ExternalProject_Add(${LIBRARY_NAME}
		PREFIX			${THIRD_PARTY_LIBS_PATH}
		URL				${LIBRARY_URL}
		CMAKE_ARGS		${_CMAKE_ARGS}
		TMP_DIR			${_TMP_DIR}
		STAMP_DIR		${_STAMP_DIR}
		DOWNLOAD_DIR	${_DOWNLOAD_DIR}
		SOURCE_DIR		${_SOURCE_DIR}
		BINARY_DIR		${_BINARY_DIR}
		INSTALL_DIR		${_INSTALL_DIR}
		LOG_DIR			${_LOG_DIR}
		TIMEOUT 15
		TLS_VERIFY ON
		LOG_DOWNLOAD 1
		LOG_BUILD 1
	)
	
	# Group all dependencies into a separate solution folder.
	set_target_properties(${LIBRARY_NAME} PROPERTIES FOLDER Dependencies)
	
	unset(LIBRARY_NAME)
	unset(LIBRARY_URL)
	
	unset(_TMP_DIR)
	unset(_STAMP_DIR)
	unset(_DOWNLOAD_DIR)
	unset(_SOURCE_DIR)
	unset(_BINARY_DIR)
	unset(_INSTALL_DIR)
	unset(_LOG_DIR)
	unset(_CMAKE_ARGS)
endmacro()

# Links external dependency to required project.
macro(link_external_dependency name)
	# Try to load library configuration.
	include("ThirdParty/${name}" REQUIRED)
	
	# Get installation directory of the library.
	ExternalProject_Get_property(${name} INSTALL_DIR)

	# Include directories.
	include_directories(${PROJECT_NAME} "${INSTALL_DIR}/include")
	
	# Add as a dependency to the project.
	add_dependencies(${PROJECT_NAME} ${name})
endmacro()

# Add source group.
macro(add_source_group group_name)
	# Init group path.
	set(GRP_PATH "")
	
	# Set source variable.
	set(SRC_GROUP ${ARGN})

	# Check if group paths are separated by dot character.
	string(REGEX MATCHALL "^[A-Za-z]*[\.][A-Za-z]+$" HAS_DOT_CHAR ${group_name})
	
	if(HAS_DOT_CHAR)
		# Create a list of paths from the group name.
		string(REPLACE "." ";" GRP_TREE_LIST ${group_name})
		
		# Append paths separated by dot.
		foreach(path ${GRP_TREE_LIST})
			string(APPEND GRP_PATH "${path}\\\\")
		endforeach()	
	else()
		set(GRP_PATH ${group_name})
	endif()

	# Add project source group.
	source_group(${GRP_PATH} FILES ${SRC_GROUP})
	
	# Add sources to the project src variable.
	list(APPEND ${PROJECT_NAME}_SOURCES ${SRC_GROUP})
	
	# Reset variables.
	unset(GRP_PATH)
	unset(SRC_GROUP)
	unset(HAS_DOT_CHAR)
	unset(GRP_TREE_LIST)
endmacro()

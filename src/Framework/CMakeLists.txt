cmake_minimum_required(VERSION 2.8)

set(NAME Framework)
project(${NAME})

# Customize these
set(PROJECT_HEADER_ROOT ${CMAKE_SOURCE_DIR}/include/GM/Framework)
set(PROJECT_SOURCE_ROOT ${CMAKE_SOURCE_DIR}/src/Framework)

set(PROJECT_FOLDERS Components Systems Totem Utilities Managers IO Templates Primitives)
# end customization

# initialize with possible files in root
file(GLOB Headers ${PROJECT_HEADER_ROOT}/*.h)
file(GLOB Sources ${PROJECT_SOURCE_ROOT}/*.cpp)

source_group("Header Files\\" FILES ${Headers})
source_group("Source Files\\" FILES ${Sources})

# Set up rest of folders
foreach(folder ${PROJECT_FOLDERS})
	file(GLOB folder_headers ${PROJECT_HEADER_ROOT}/${folder}/*.h ${PROJECT_HEADER_ROOT}/${folder}/*.inl)
	file(GLOB folder_sources ${PROJECT_SOURCE_ROOT}/${folder}/*.cpp)

	# append found files to relevant list
	list(APPEND Headers ${folder_headers})
	list(APPEND Sources ${folder_sources})

	string(REPLACE "/" "\\" folderForSourceGroup ${folder})

	# Set up relevant source group
	source_group("Header Files\\${folderForSourceGroup}" FILES ${folder_headers} ${folder_headers_inl})
	source_group("Source Files\\${folderForSourceGroup}" FILES ${folder_sources})
endforeach()

add_library(${NAME} ${GM_LIBRARY_TYPE} ${Headers} ${Sources})
# This library depends on the following libraries
target_link_libraries(${NAME}
	Core # Core has it's own dependencies, they will get pulled automatically
	assimp # These should probably be moved to Application
	SOIL2
	LodePNG)


set_target_properties(${NAME} PROPERTIES FOLDER "GM")

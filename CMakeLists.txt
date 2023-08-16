cmake_minimum_required (VERSION 3.8)

project ("game-of-life")

add_executable (game-of-life "main.cpp"  "src/board_parser.cpp"  "src/board.cpp")
target_compile_features(game-of-life PUBLIC cxx_std_17)
target_include_directories(game-of-life PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_custom_command(
	TARGET game-of-life POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/boards/ $<TARGET_FILE_DIR:game-of-life>)

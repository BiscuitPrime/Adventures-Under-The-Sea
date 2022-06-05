
add_executable(mainLauncher mainLauncher.cpp "imgui/imconfig.h" "imgui/imgui-SFML.cpp" "imgui/imgui-SFML.h" "imgui/imgui-SFML_export.h" "imgui/imgui.cpp" "imgui/imgui.h" "imgui/imgui_demo.cpp" "imgui/imgui_draw.cpp" "imgui/imgui_internal.h" "imgui/imgui_widgets.cpp" "imgui/imstb_rectpack.h" "imgui/imstb_textedit.h" "imgui/imstb_truetype.h")

target_link_libraries(mainLauncher PUBLIC src pugixml sfml-graphics)

add_custom_target(copy-resources ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources
                   DEPENDS ${CMAKE_SOURCE_DIR}/resources 
                   DEPENDS ${CMAKE_SOURCE_DIR}/resources/Sprites
                   DEPENDS ${CMAKE_SOURCE_DIR}/resources/tilemaps
                   COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/resources
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_dependencies(mainLauncher copy-resources)

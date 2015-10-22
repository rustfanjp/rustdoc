cmake_minimum_required (VERSION 2.8)

add_custom_target (RUSTFUNJP_EXTERN_RUSTBOOK_COPY COMMAND "cp" "${CMAKE_CURRENT_SOURCE_DIR}/*" "./" "-r")
add_custom_command (OUTPUT "rustbook" COMMAND "cargo" "build" COMMAND "cp" "${CMAKE_CURRENT_BINARY_DIR}/target/debug/rustbook" "./rustbook" DEPENDS RUSTFUNJP_EXTERN_RUSTBOOK_COPY)
add_custom_target (RUSTFUNJP_EXTERN_RUSTBOOK_BUILD SOURCES "rustbook")

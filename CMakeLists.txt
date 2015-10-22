cmake_minimum_required (VERSION 2.8)

project (RUSTFANJP)

add_subdirectory ("extern")

function (make_doc TARGET_NAME DIR_NAME)
  add_custom_target ("${TARGET_NAME}_BUILD"
    COMMAND "cp" "${PROJECT_BINARY_DIR}/extern/rustbook/rustbook" "./"
    COMMAND "cp" "${CMAKE_CURRENT_SOURCE_DIR}/*" "./" "-r"
    COMMAND "./rustbook" "build"
    DEPENDS RUSTFUNJP_EXTERN_RUSTBOOK_BUILD
  )

  add_custom_target ("${TARGET_NAME}_FORMAT"
    COMMAND "${PROJECT_SOURCE_DIR}/tool/format.sh"
    WORKING_DIRECTORY "./_book"
    DEPENDS "${TARGET_NAME}_BUILD"
  )

  add_custom_target("${TARGET_NAME}_DOC" ALL
    COMMAND "mkdir" "${PROJECT_BINARY_DIR}/doc/${DIR_NAME}" "-p"
    COMMAND "cp" "${CMAKE_CURRENT_BINARY_DIR}/_book/*.html" "${PROJECT_BINARY_DIR}/doc/${DIR_NAME}/" "-r"
    COMMAND "cp" "${CMAKE_CURRENT_BINARY_DIR}/_book/*.js" "${PROJECT_BINARY_DIR}/doc/${DIR_NAME}/" "-r"
    COMMAND "cp" "${CMAKE_CURRENT_BINARY_DIR}/_book/*.css" "${PROJECT_BINARY_DIR}/doc/${DIR_NAME}/" "-r"
    DEPENDS "${TARGET_NAME}_FORMAT"
  )
endfunction (make_doc)

add_subdirectory ("src")

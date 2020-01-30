find_program(PLATUML plantuml)
if (NOT PLATUML)
    message(FATAL_ERROR "Missing PlatUML binary!")
endif()
set(DIAGRAM_PUML ${CMAKE_CURRENT_SOURCE_DIR}/class.puml)
set(DIAGRAM_SVG ${CMAKE_CURRENT_BINARY_DIR}/class.svg)
add_custom_command(
    OUTPUT ${DIAGRAM_SVG}
    COMMAND ${PLATUML} -o ${CMAKE_CURRENT_BINARY_DIR} -tsvg ${DIAGRAM_PUML}
    MAIN_DEPENDENCY ${DIAGRAM_PUML}
    COMMENT "Rendering ${DIAGRAM_SVG} from ${DIAGRAM_PUML}")
add_custom_target(07_abstract_factory_pattern_uml DEPENDS ${DIAGRAM_SVG})

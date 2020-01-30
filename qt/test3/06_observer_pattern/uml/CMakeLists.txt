find_program(PLATUML plantuml)
set(DIAGRAM_SVG ${CMAKE_CURRENT_BINARY_DIR}/diagram.svg)
add_custom_command(
    OUTPUT ${DIAGRAM_SVG}
    COMMAND ${PLATUML} -o ${CMAKE_CURRENT_BINARY_DIR} -tsvg ${CMAKE_CURRENT_SOURCE_DIR}/diagram.puml
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/diagram.puml
    COMMENT "Rendering UML diagram")
add_custom_target(06_observer_pattern_uml DEPENDS ${DIAGRAM_SVG})

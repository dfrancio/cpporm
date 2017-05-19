set(THEME_SOURCE "${sphinx_rtd_theme_DIR}/src/sphinx_rtd_theme/sphinx_rtd_theme")
set(THEME_OUTPUT "${SPHINX_THEME_DIR}/${SPHINX_HTML_THEME}")
file(COPY "${THEME_SOURCE}/" DESTINATION ${THEME_OUTPUT})

message(STATUS ${THEME_SOURCE})
message(STATUS ${THEME_OUTPUT})

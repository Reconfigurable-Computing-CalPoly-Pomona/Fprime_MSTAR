####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
#
# Note: using PROJECT_NAME as EXECUTABLE_NAME
####
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/MathOpPortAi.xml"
  "${CMAKE_CURRENT_LIST_DIR}/MathResultPortAi.xml"
)

register_fprime_module()
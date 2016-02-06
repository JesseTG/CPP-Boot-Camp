if (${UNIX})
  set (DESKTOP $ENV{HOME})
else()
  set (DESKTOP $ENV{USERPROFILE}/Desktop)
endif()

set(PRJ      ${DESKTOP}/common/svn )
set(FILELIST ${PRJ}/src/source.txt )

project(project_name)

include_directories(
  ${PRJ}/src
  ${PRJ}/includes
)

# Load SRC variable from file
file(READ ${FILELIST} SRC)
string(REGEX REPLACE  "#.*$"  ""  SRC  ${SRC})
string(REPLACE        "\n"    ";" SRC  ${SRC})

add_executable(${PROJECT_NAME} ${SRC} )

foreach (f ${SRC})
  set_source_files_properties(${f} PROPERTIES LANGUAGE CXX)
endforeach(f)

# Set an app icon on Windows or macOS
#
# This module is used only for the examples, it's not necessary for Elements
# to work, so if you want to use a custom icon on your application, you can
# modify and include it into the CMake configuration of your application.
# On BSD or Linux like systems using Freedesktop desktop files this is not needed.

set(ELEMENTS_APP_ICON "${ELEMENTS_ROOT}/resources/windows/cycfi.rc")
list(APPEND ELEMENTS_APP_SOURCES ${ELEMENTS_APP_ICON})


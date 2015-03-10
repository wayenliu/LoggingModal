PROJECT (LoggingMode)

#message(${PROJECT_SOURCE_DIR})
#message(${PROJECT_BINARY_DIR})

add_subdirectory(UnitTest)
add_subdirectory(UnitTest DllOut)

#增加路径
include_directories(${PROJECT_SOURCE_DIR}/LogOpration/LogOprationHeader/)
#include_directories(${PROJECT_SOURCE_DIR}/LogOpration/LogOprationCpp/)

#设置模块集
set (write_class
    "LogOpration/LogOprationHeader/common_define.h"
    "LogOpration/LogOprationHeader/log_define.h"
    "LogOpration/LogOprationHeader/write_log.h"
    "LogOpration/LogOprationHeader/LoggingMode.h"
    "LogOpration/LogOprationCpp/log_define.cpp"
    "LogOpration/LogOprationCpp/write_log.cpp"
    "LogOpration/LogOprationCpp/LoggingMode.cpp"
)



#生成dll
add_library(LoggingModeDLL SHARED ${write_class})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/UnitTest/DllOut)

#add_executable(hello ${APP_SRC})
#target_link_libraries(LoggingMode PROPERTIES OUTPUT_NAME "LoggingMode")

#include "status_report.h"

static char* ErrorStrList[] = {
    "CORRECT",
    "WARNING_NOT_ENOUGH_DATA",
    "WARNING_PARAM_KEY_LACK",
    "WARNING_MAX",
    "ERROR_SUB_FUNC_FAILED",
    "ERROR_WRONG_PARAM",
    "ERROR_END",
};

SType StatusPrinter(SType Stype, uint32_t line, const char* funcName, const char* fName)
{
    printf("\r\nStatusCode[%s]\nLine[%ld]\nFuncName[%s]\nFileName[%s]\r\n",\
        ErrorStrList[Stype], line, funcName, fName);
    return CORRECT;
}
SType StatusPrinterWithTag(SType Stype, const char* tag, uint32_t line, const char* funcName, const char* fName)
{
    printf("\r\nStatusCode[%s]Tag[%s]\nLine[%ld]\nFuncName[%s]\nFileName[%s]\r\n",\
        ErrorStrList[Stype],tag, line, funcName, fName);
    return CORRECT;
}

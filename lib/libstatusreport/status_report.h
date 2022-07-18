#ifndef __ERROR_REPORT_H__
#define __ERROR_REPORT_H__

#include <stdio.h>
#include <stdint.h>
typedef enum ErrorListT {
    CORRECT = 0,
    WARNING_NOT_ENOUGH_DATA,
    WARNING_PARAM_KEY_LACK,
    WARNING_MAX,
    ERROR_SUB_FUNC_FAILED,
    ERROR_WRONG_PARAM,
    ERROR_END,
} SType;

#define S_REPO(Stype) StatusPrinter(Stype, __LINE__, __FUNCTION__, __FILE__)
#define S_REPO_RETURN(Stype) do {\
        S_REPO(Stype);\
        return Stype;\
    } while (0);
#define S_REPO_CONTINUE(Stype) do {\
        S_REPO(Stype);\
        continue;\
    } while (0);
#define S_REPO_BREAK(Stype) do {\
        S_REPO(Stype);\
        break;\
    } while (0);

#define S_REPO_TAG(Stype, tag) StatusPrinterWithTag(Stype, tag, __LINE__, __FUNCTION__, __FILE__)
#define S_REPO_TAG_RETURN(Stype, tag) do {\
        S_REPO_TAG(Stype, tag);\
        return Stype;\
    } while (0);
#define S_REPO_TAG_CONTINUE(Stype, tag) do {\
        S_REPO_TAG(Stype, tag);\
        continue;\
    } while (0);
#define S_REPO_TAG_BREAK(Stype, tag) do {\
        S_REPO_TAG(Stype, tag);\
        break;\
    } while (0);



SType StatusPrinter(SType Stype, uint32_t line, const char* funcName, const char* fName);
SType StatusPrinterWithTag(SType Stype, const char* tag, uint32_t line, const char* funcName, const char* fName);

#endif

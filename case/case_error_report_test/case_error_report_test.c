#include "status_report.h"

SType TestWhileMacro()
{
    if(1-2)
        S_REPO_RETURN(WARNING_PARAM_KEY_LACK);
    return CORRECT;
}

int main()
{
    S_REPO(WARNING_PARAM_KEY_LACK);
    S_REPO(ERROR_WRONG_PARAM);
    SType status = CORRECT;
    status = TestWhileMacro();
    printf("status[%ld]\n",status);
    char tag[] = "correct";
    S_REPO_TAG(CORRECT, tag);
    return CORRECT;
}

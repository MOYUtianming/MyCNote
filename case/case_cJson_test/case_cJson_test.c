#include "main.h"
#include "cJSON.h"
#include "status_report.h"

int main(int argc, char** argv)
{
    cJSON* cjsonObj = NULL;
    char buf[2048] = {0};
    FILE* fp = fopen("F:/Library/CodeLib/C/config/aac.json", "r");
    fread(buf, 2048, 1, fp);
    cjsonObj = cJSON_Parse(buf);
    cJSON* codecJ = cJSON_GetObjectItemCaseSensitive(cjsonObj, "codec");
    printf("%s\n",codecJ->valuestring);
    cJSON* modJ = cJSON_GetObjectItemCaseSensitive(cjsonObj, "mod");
    printf("%s\n",modJ->valuestring);
    cJSON_Delete(cjsonObj);
    return 0;
}

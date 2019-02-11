#include "main.h"

bool strcmp_check(const char *line, const char *sub_str){
    int count = strlen(sub_str);
    printf("输入字符串:%s, 匹配:%s\n", line, sub_str);
    printf("字符串长度:%d\n", count);
    
    for(size_t i = 0; i < count; i++)
    {
        if (line[i] != sub_str[i]){
            printf("%s 匹配失败!\n", line);
            return false;
        }
    }
    return true;
}

struct keyword_list{

};

bool strcmp_check_list(const char *line, char *result){
    
}

bool Greetings(const char *line, char *result){
    if (strcmp_check(line, "你好")){
        strcpy(result, "您好！");
        return true;
    };
    if (strcmp_check(line, "您好")){
        strcpy(result, "您好！很高兴为您服务...");
        return true;
    };
    if (strcmp_check(line, "在")){
        strcpy(result, "您好！在的");
        return true;
    };
    return false;
}

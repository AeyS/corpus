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
        }else{
            printf("%s 匹配成功!\n", line);
        }
    }
    return true;
}

/**
 * 当存在几个关键词出现在同一句短语内的时候，则判断成立。
 * */
bool strcmp_check_list(const char *line, char *sub_str){
    int sp_count_length = count(sub_str, " ")+1;
    // 首先分割匹配字符串
    char *result[sp_count_length];
    split(sub_str, " ", result);
    // 然后将关键词逐个进行匹配，如果有一个未出现在短句中，则判断匹配失败！
    for(size_t i = 0; i < sp_count_length; i++)
    {
        if (count(line, result[i]) == 0)
            return false;
    }
    return true;
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
    if (strcmp_check_list(line, "鲜花 价格 多少")){
        strcpy(result, "三角梅，50元一株带花盆");
        return true;
    }
    return false;
}

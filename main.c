#include "main.h"

// 分析语句，并返回答案
void analysis()
{
  printf("请输入汉字进行匹配 %s\n", "Aeys");
  char question[1024*3], result[1024];
  fflush(stdout);
  
  while(printf(">"),scanf("%79s", question)){
    bool status = Greetings(question, result);
    if (status == true){
      printf("分析回答: %s\n\n", result);
    } else {
      printf("error-code: %d\n", status);
    }
  }
}

void string_split_for(){
  char str[] = "hello 那你干嘛 好的 我很喜欢这种花 因为它很beautiful!";
  char *result[count(str, " ")+1];
  int length = split(str, " ", result);
  
  for(int i = 0; i < length; i++)
  {
    // 一般出现空白，基本是由于存储空间不够大引起的
    printf("result[%d]", i);
    printf(" = %s\n", result[i]);
    // printf("result[%d] = %s, length: %d\n", i, result[i], length);
  }
  printf("===========\n");
}

void string_count(){
  char str[] = "hello 那你干嘛 好的";
  // str_index_of(question);
  count(str, "e");
  // printf("str: %s\n", str);
  // char result[500];
  // substring("how are you, Im fine!", 0, 1, result);
  // clear_string(&str);
  // printf("%s\n", str);
  // printf("result: %s\n", result);
  // printf("%d\n", compare(result, " are y"));
}

void main(){
  analysis();
}
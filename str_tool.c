#include "main.h"

void debug(char *func_name, char *info){
    printf("F[%s] %s\n", func_name, info);
}

int split(const char *src, const char *delim, char *result[]){
  char *pch;
  int index = 0;
  char *src_copy;
  src_copy = malloc(strlen(src));
  strcpy(src_copy, src);
  // printf("src_copy = %s\n", src_copy);
  pch = strtok(src_copy, delim);
  // printf("result[%d] = %s\n", index, pch);
  result[index] = pch;
  index++;
  while(pch != NULL){
    pch = strtok(NULL, delim);
    if (pch == NULL)
     break;
    result[index] = pch;
    // printf("result[%d] = %s, %s\n", index, result[index], pch);
    index++;
  }
  printf("length: %d \n===========\n", index);
  return index;
}

int str_index_of(char *line){
  char hanzi_temp[5];
  for(int i=0; i<strlen(line); i++){
    if (line[i] < 0){
      //strcat (hanzi_temp, line[i]);
    }else{
      printf( "hanzi_temp: %s", hanzi_temp);
    }
    printf("%d ", line[i]);
  }
  printf("\n");
  return 0;
}

bool compare(char *src, const char *delim){
  size_t delim_length = strlen(delim), src_length = strlen(src);
  char spr[500];
  if (delim_length != src_length){
    sprintf(spr, "src = '%s', delim = '%s'", src, delim);
    debug("compare", spr);
    sprintf(spr, "当前长度不准确：delim_length = %ld, src_length = %ld", delim_length, src_length);
    debug("compare", spr);
    return false;
  }
  for(int i = 0; i < delim_length; i ++){
    if (src[i] != delim[i]){
      // printf("src = %c, delim = %c", src[i], delim[i]);
      return false;
    }
  }
  sprintf(spr, "src = '%s', delim = '%s'", src, delim);
  debug("compare", spr);
  return true;
}

void clear_string(char * result){
  memset(result, 0, sizeof(result));  
}

void substring(char *src, int start, int end, char *result){
  clear_string(result);
  size_t index = 0;
  for(int i = start; i < end; i++)
  {
    // printf("%d, %c\n", i, src[i]);
    result[index] = src[i];
    index++;
  }
  result[ index ] = '\0';
}

int count(char *src, const char *delim){
  char spr[500];
  sprintf(spr, "src: %s, delim: %s", src, delim);
  debug("count", spr);
  size_t src_length = strlen(src), delim_length = strlen(delim), index = 0, count_length = 0;
  bool sub_string_bool = false;
  char substring_result[delim_length+1];
  while((index+delim_length) < src_length){
    substring(src, index, index+delim_length, substring_result);
    if (compare(substring_result, delim)){
        sprintf(spr, "index: %ld, src_length: %ld, delim_length: %ld, count_length: %ld"
        , index
        , src_length
        , delim_length
        , count_length);
        debug("count", spr);
        sprintf(spr, "count: s=%ld, e=%ld, %s, %s\n", index, index+delim_length, substring_result, delim);
        debug("count", spr);
        index += delim_length;
        count_length ++ ;
    }else{
        index ++;
    }
    // printf("%ld\n", index);
  }
  return count_length;
}
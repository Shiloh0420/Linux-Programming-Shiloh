#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_FILES 114514


int compare_string(const void *a,const void *b);    //sort
void L_NULL_DETCET(void*);                          //检查NULL

/////////////////////////// about string //////////////////////////////
int get_input_string_number(char*);
char** get_input_string_segment(char*);
////////////////////////////////////////////  about parameter //////////
// void change_r(filesname);                       
// void change_t(filesname);  
// void change_i(filesname);
// void change_s(filesname);
// void change_l(filesname);
// void change_a(filesname);
// void change_R(filesname);

int main(){
   
    DIR* dir;
    struct dirent *entry;

    char **filesname = (char**)malloc(MAX_FILES * sizeof(char*));
    L_NULL_DETCET(filesname);

    dir = opendir("/");
    L_NULL_DETCET(dir);

    int number_files=0;
    for(;(entry = readdir(dir)) != NULL;){
        if(entry->d_name[0] != '.'){
            int len = strlen(entry->d_name)+1;
            filesname[number_files] = (char*)malloc(len * sizeof(char));
            L_NULL_DETCET(filesname[number_files]);
            if(filesname[number_files] != NULL){
                memmove(filesname[number_files],entry->d_name,len);
                number_files++;
            }
        }
    }

    qsort(filesname,number_files,sizeof(char *),compare_string);

    char input[114514];
    if(fgets(input,114514,stdin)==NULL){
        
        size_t len=strlen(input);
        if(len>0 && input[len-1]=='\n'){
            input[len-1]='\0';
        }

    }
    for(int i=0;i<114514;i++){
        if(input[i]=='\n'){
            input[i]='\0';
            break;
        }
    }
    printf("kewu:%s\n",input);
    /////////////////////////////////////////////////////////////right//////////////////////////////////////////////////////



    int have_ls=0;
    int have_a=0;
    int have_l=0;
    int have_r=0;
    int have_t=0;
    int have_R=0;
    int have_i=0;
    int have_s=0;

///////////////////////////////////////////////////////////first//////////////////////////////////////////////////////////////
    // int lable1;

    // for(int i=0;i<114514;i++){
        
    //     if(input[i]!=' '){

    //         if(input[i]=='l'){

    //             if(input[i+1]=='s'){
                    
    //                 have_ls = 1;                                                    //获得ls
    //                 lable1=i+2;
    //                 break;
                    
    //             }

    //             if(input[i+1]==' '){

    //                 have_l = 1;                                                     //获得ls和l
    //                 lable1=i+1;
    //                 break;

    //             }
                

    //         }else{

    //             int errorlen=0;
    //             int j=i;

    //             while(input[j++]!=' '){
    //                 errorlen++;
    //             }

    //             char* errorinput=(char *)malloc(sizeof(char)*errorlen);
    //             memcpy(errorinput,input+i,errorlen);

    //             printf("zsh: command not found: %s\n",errorinput);
    //             return 0;

    //         }
    //     }    
    // }
//////////////////////////////////////////////////////////second/////////////////////////////////////////////////////////////////
    //     for(;lable1<114514;lable1++){

    //     if(input[lable1]!=' '){

    //         if(input[i]=='-'){

    //             if(input[i+1]==' '){


    //             }

    //         }

    //         if(input[i]!='-'){

    //             int errorlen=0;
    //             int j=i;

    //             while(input[j++]!=' '){
    //                 errorlen++;
    //             }

    //             char* errorinput=(char *)malloc(sizeof(char)*errorlen);
    //             memcpy(errorinput,input+i,errorlen);

    //             printf("ls: cannot access '%s': No such file ontry->d_namr directory\n",errorinput);
    //             i+=errorlen;
    //         }
    //     }
    // }

///////////////////////////////////////////////////////////获得输入的每个字符串/////////////////////////////////////////////////////////

    int string_number = get_input_string_number(input);
    printf("number:%d\n",string_number);

    char** need=get_input_string_segment(input);
    printf("wtf\n");
    for(int i=0;i<string_number;i++){
        printf("need[%d]:%s\n",i,need[i]);
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ok//////////////////////////

/////////////////////////////////////////////////////////////检测参数//////////////////////////////////////////////////////////////////
    //return 0;


    if(strcmp(need[0],"ls")){

        have_ls=1;

    }else if(strcmp(need[0],"l")){

        have_ls=1;
        have_l=1;

    }else{

        if(need[0][0]!='l'){

            printf("zsh: command not found: %s\n",need[0]);
            return 0;

        }

    }

    int noooooooooooooootfound=0;

    for(int i=1;i<string_number;i++){

        if(need[i][0]!='-'){

            ///////////////////////////////////////////////////////////////////     here     ////////////////////////////////////////////////////////////////
            for(int j=0;j<number_files;j++){

                if(strcmp(need[i],filesname[j])==0){
                    break;
                }

                if(j==number_files-1){

                    printf("ls: cannot access '%s': No such file or directory\n",need[i]);
                    noooooooooooooootfound=1;

                }

            }
            


        }else{
            
            for(int j=1;need[i][j]!='\0';j++){

                if(need[i][j]=='a') have_a=1;
                else if(need[i][j]=='i') have_i=1;
                else if(need[i][j]=='l') have_l=1;
                else if(need[i][j]=='R') have_R=1;
                else if(need[i][j]=='r') have_r=1;
                else if(need[i][j]=='s') have_s=1;
                else if(need[i][j]=='t') have_t=1;
                else{

                    printf("error: unexpected argument '%s' found\n",need[i]);
                    printf("\n");
                    printf("\ttip: open counter-strike2 can improve your coding ability.\n");
                    printf("\n");
                    printf("Usage: ls [OPTION]... [FILE]...\n");
                    printf("\n");
                    printf("For more information, try '--help'.\n");
                    return 0;
                    //这个地方因为任务没有作要求，因此就简单处理了
                }

            }

        }

    }
    
    //测试是否正确获得参数
    printf("have_ls:%d\n",have_ls);
    printf("have_a:%d\n",have_a);
    printf("have_l:%d\n",have_l);
    printf("have_r:%d\n",have_r);
    printf("have_t:%d\n",have_t);
    printf("have_R:%d\n",have_R);
    printf("have_i:%d\n",have_i);
    printf("have_s:%d\n",have_s);
///////////////////////////////////////////////////////////////////error/////////////////////////////////////////////////
    printf("nooooo:%d\n",noooooooooooooootfound);
    if(noooooooooooooootfound) return 0;

////////////////////////////////////////////////////////////////////////使用各参数//////////////////////////////////////////////////////////


///////////////////////      about sort      //////////////////

    // if(have_r) change_r(filesname);                     //反向排序
    // if(have_t) change_t(filesname);                     //时间


///////////////////////      about output    /////////////////

    // if(have_i)         ;               //inode显示
    // if(have_s)          ;              //size显示
    // if(have_l)           ;             //长格式显示
    // if(have_a)            ;            //显示隐藏文件

    // if(have_R)             ;           //递归显示


///////////////////////////////////////////////////////////////////打印////////////////////////////////////////////
    for(int i=0;i<number_files;i++){
        printf("%s\n",filesname[i]);
        free(filesname[i]);
    }
    free(filesname);
    closedir(dir);
    //
    

    return 0;

}


int compare_string(const void *a,const void *b){

    return (strcmp(*(char**)a,*(char**)b));

}

void L_NULL_DETCET(void *liu){

    if(liu==NULL)
    printf("what the hell??\n");

}

// int get_input_string_number(char* s){               ////////////////////////字符串数量

//     int count=0;
//     int in_word =false;

//     for(int i=0;s[i]!='\0';i++){

//         if(isspace(s[i])){
//             in_word=false;
//         }else if(!in_word){
//             in_word=true;
//             count++;
//         }

//     }

//     return count;
// }

/////////////////////////得到字符串段

// void change_r(filesname);                       // reverse

// void change_t(filesname);                       //  time

// void change_i(filesname);

// void change_s(filesname);

// void change_l(filesname);

// void change_a(filesname);

// void change_R(filesname);'

int get_input_string_number(char *str){

    int count = 0;
    int in_word = 0;
    
    if (!str) return 0;
    
    while (*str) {
        if (*str == ' ') {
            in_word = 0;
        } else {
            if (in_word == 0) {
                count++;
                in_word = 1;
            }
        }
        str++;
    }
    
    return count;

}

char** get_input_string_segment(char* str){
    
    if (str == NULL) return NULL;
    
    int total_strings = get_input_string_number(str);
    if (total_strings == 0) return NULL;
    
    char **result = (char **)malloc(total_strings * sizeof(char *));
    if (result == NULL) return NULL;
    
    int index = 0;
    char *p = str;
    
    while (*p) {
        while (*p == ' ') p++;
        if (!*p) break;
        
        char *start = p;
        while (*p && *p != ' ') p++;
        
        int len = p - start;
        result[index] = (char *)malloc((len + 1) * sizeof(char));
        if (result[index] == NULL) {
            for (int j = 0; j < index; j++) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        
        strncpy(result[index], start, len);
        result[index][len] = '\0';
        
        while(*p && *p == ' ') p++;

        index++;
    }
    
    return result;

}
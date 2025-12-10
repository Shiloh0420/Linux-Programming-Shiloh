#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<ctype.h>
#include<stdbool.h>
#include<unistd.h>

#define MAX_FILES 114514

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_BGREEN  "\033[1;32m"  // 亮绿色（加粗）
#define COLOR_RED     "\033[31m"
#define COLOR_BLUE    "\033[34m"
struct  all_information{
    char name[256];
    int inode;
    struct stat* stat_info;
};

int compare_by_name_string(const void*,const void*);    //sort
int compre_by_time(const void*,const void*);   //sort
void L_NULL_DETCET(void*);                          //检查NULL

/////////////////////////// about string //////////////////////////////
int get_input_string_number(char*);
char** get_input_string_segment(char*);
////////////////////////////////////////////  about parameter //////////
// void change_r(filesname);////////////////////////////////////////////////////////////////////////////////////////////                       
// void change_t(filesname);/////////////////////////////////////////////////////////////////////////////////////////////////  
// void change_i(filesname);/////////////////////////////////////////////////////////////////////////////////////////////
// void change_s(filesname);////////////////////////////////////////////////////////////////////////////////////////////////
// void change_a(char**,int);/////////////////////////////////////////////////////////////////////////////////////////
// void change_R(filesname);
int count_dir_entry(DIR*);

int handle(char*,int,int,int,int,int,int,int);

void l_handle(struct all_information**,int);

int main(){
   
    // DIR* dir;
    // struct dirent *entry;

    // char **filesname = (char**)malloc(MAX_FILES * sizeof(char*));
    // L_NULL_DETCET(filesname);

    // dir = opendir("/");
    // L_NULL_DETCET(dir);

    // int number_files=0;
    // for(;(entry = readdir(dir)) != NULL;){
    //     int len = strlen(entry->d_name)+1;
    //     filesname[number_files] = (char*)malloc(len * sizeof(char));
    //     L_NULL_DETCET(filesname[number_files]);
    //     if(filesname[number_files] != NULL){
    //     memmove(filesname[number_files],entry->d_name,len);
    //     number_files++;
    //     }
    // }

    // qsort(filesname,number_files,sizeof(char *),compare_string);

    while(1){
    char input[114514];

    // char exe_path[114514];
    // ssize_t count = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
    
    // exe_path[count] = '\0';


    // printf("%s ",exe_path);
    // printf("\033[1;34m~\033[1;34m");
    // printf("\033[34m/学习这一块/\033[34m");
    // printf("\033[1;34mc语言这一块\033[1;34m ");
    // printf("\033[1;32m> ");
    printf("\033[34m上善若水，水善利万物而不争 ——《道德经》 \033[1;32m❯\033[0m ");

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
    //printf("kewu:%s\n",input);
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
    // printf("number:%d\n",string_number);

    char** need=get_input_string_segment(input);
    //printf("wtf\n");
    // for(int i=0;i<string_number;i++){
    //     printf("need[%d]:%s\n",i,need[i]);
    // }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ok//////////////////////////

/////////////////////////////////////////////////////////////检测参数//////////////////////////////////////////////////////////////////
    //return 0;

    if(string_number==0) break;
    if(strcmp(need[0],"ls")==0){

        have_ls=1;

    }else if(strcmp(need[0],"l")==0){

        have_ls=1;
        have_l=1;

    }else{


            printf("zsh: command not found: %s\n",need[0]);

    }

    if(!have_ls) continue;


    int argument_not_found=0;
    for(int i=1;i<string_number;i++){

        // if(need[i][0]!='-'){

        //     ///////////////////////////////////////////////////////////////////     here     ////////////////////////////////////////////////////////////////
        //     for(int j=0;j<number_files;j++){

        //         if(strcmp(need[i],filesname[j])==0){
        //             break;
        //         }

        //         if(j==number_files-1){

        //             printf("ls: cannot access '%s': No such file or directory\n",need[i]);
        //             noooooooooooooootfound=1;

        //         }

        //     }
            


        // }else
        if(!(strcmp(need[i],"--help"))){
            
            printf("List directory contents.\n");
            printf("Ignore files and directories starting with a '.' by default\n");
            printf("\n");
            printf("Usage: ls [OPTION]... [FILE]...\n");
            printf("\n");
            printf("Arguments:\n");
            printf("  [paths]...\n");
            printf("\n");
            printf("Options:\n");
            printf("  --help                                     oh I get a little help from my friends\n");
            printf("  -a                                         applepen pinepple pen ppap .\n");
            printf("  -i                                         i want to break free\n");
            printf("  -l                                         lovelive good good\n");
            printf("  -R                                         RNB's king David Tao\n");
            printf("  -r                                         rip Kobe Bryant\n");
            printf("  -s                                         sb code sb life sb me sb everyone\n");
            printf("  -t                                         time and tide wait for no man\n");
            printf("\n");
            printf("The TIME_STYLE argument can be full-iso, long-iso, iso, locale or +FORMAT. FORMAT is interpreted like in date. Also the TIME_STYLE environment variable sets the default style to use.");
            printf("Let me take you down Cause I'm going to strawberry fields Nothing is real And nothing to hung about Strawberry fields forever Strawberry fields forever Strawberry fields forever.");
            printf("\n");
            argument_not_found=1;
            break;
        }

        if(need[i][0]=='-'){
            
            for(int j=1;need[i][j]!='\0';j++){

                if(need[i][j]=='a') have_a=1;
                else if(need[i][j]=='i') have_i=1;
                else if(need[i][j]=='l') have_l=1;
                else if(need[i][j]=='R') have_R=1;
                else if(need[i][j]=='r') have_r=1;
                else if(need[i][j]=='s') have_s=1;
                else if(need[i][j]=='t') have_t=1;
                else{

                    printf("\033[31merror\033[0m: unexpected argument '\033[33m%s\033[0m' found\n",need[i]);
                    printf("\n");
                    printf("  \033[32mtip\033[0m: open counter-strike2 can improve your coding ability.\n");
                    printf("\n");
                    printf("Usage: ls [OPTION]... [FILE]...\n");
                    printf("\n");
                    printf("For more information, try '--help'.\n");
                    argument_not_found=1;
                    break;
                    //这个地方因为任务没有作要求，因此就简单处理了
                }

            }

        }

    }
    
    if(argument_not_found) continue;
    //测试是否正确获得参数
    // printf("have_ls:%d\n",have_ls);
    // printf("have_a:%d\n",have_a);
    // printf("have_l:%d\n",have_l);
    // printf("have_r:%d\n",have_r);
    // printf("have_t:%d\n",have_t);
    // printf("have_R:%d\n",have_R);
    // printf("have_i:%d\n",have_i);
    // printf("have_s:%d\n",have_s);
///////////////////////////////////////////////////////////////////error/////////////////////////////////////////////////
    // printf("noooootfound:%d\n",noooooooooooooootfound);
    

    int it_have_file_name=0;                                      
    //////////////////////////////////////////打开当前目录//////////////////////////////////////////////////////////
        DIR* dir_current;
        struct dirent *entry;

        char **filesname = (char**)malloc(MAX_FILES * sizeof(char*));
        L_NULL_DETCET(filesname);

        dir_current = opendir(".");
        L_NULL_DETCET(dir_current);

        int number_files=0;
        for(;(entry = readdir(dir_current)) != NULL;){
            int len = strlen(entry->d_name)+1;
            filesname[number_files] = (char*)malloc(len * sizeof(char));
            L_NULL_DETCET(filesname[number_files]);
            if(filesname[number_files] != NULL){
            memmove(filesname[number_files],entry->d_name,len);
            number_files++;
            }
        }


    
////////////////////////////////////////////////////////////////////////检测文件是否存在//////////////////////////////////////////////////////////


    int have_file_to_open=0;

    for(int i=1;i<string_number;i++){

        if(need[i][0]!='-'){

            /////////////////////////////////////////////////////////////////     here     ////////////////////////////////////////////////////////////////
            for(int j=0;j<number_files;j++){

                int judge_have_file = handle(need[i],have_a,have_r,have_t,have_R,have_i,have_s,have_l);
                if(judge_have_file==-1 && j==number_files-1){
                    printf("ls: cannot access '%s': No such file or directory\n",need[i]);
                }
                if(judge_have_file != -1){
                    have_file_to_open=1;
                }
                break;
            }

        }


    }

    for(int i=0;i<number_files;i++){
        free(filesname[i]);
    }
    free(filesname);
    closedir(dir_current);

    if(!have_file_to_open){

        /////////////////////////////////////////////////////////////没有文件名，打开当前目录/////////////////////////////////////////////////////
        printf("handle current dir:\n");
        handle(".",have_a,have_r,have_t,have_R,have_i,have_s,have_l);

    }

///////////////////////////////////////////////////////////////////打印////////////////////////////////////////////
    // if(have_ls&&have_a){
    //     for(int i=0;i<number_files;i++){
    //         printf("%s\n",filesname[i]);
    //     }
    //     printf("tttttttttttttttttttttttttttttttttttttttttttttttttttt\n");
    // }else if(have_ls&&!have_a){
    //     for(int i=0;i<number_files;i++){
    //         if(filesname[i][0]!='.'){
    //             printf("%s\n",filesname[i]);
    //         }
    //     }
    //     printf("ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\n");
    // }
    // for(int i=0;i<number_files;i++){
    //     free(filesname[i]);printf("tttttttttttttttttttttttttttttttttttttttttttttttttttt\n");
    // }
// void change_R(filesname);'

    // free(filesname);
    // closedir(dir_current);
    







    
}
    return 0;
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

//void no_change_a(char** filesname,int number_files);

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


//////////////////////////////////////////////////////////////////////////////////////////////////////handle函数///////////////////////////////////////////////////////////
int handle(char* openfile,int have_a,int have_r,int have_t,int have_R,int have_i,int have_s,int have_l){

    //printf("1145141919810 handle:%s\n",openfile);
    DIR* dir;
    struct dirent *entry;

    dir = opendir(openfile);
    if(dir==NULL){
        return -1;
    }

    int number_files=count_dir_entry(dir);

    struct all_information** alllist = (struct all_information**)malloc(number_files * sizeof(struct all_information*));
    L_NULL_DETCET(alllist);

    int index=0;
    for(;(entry = readdir(dir)) != NULL;index++){

        alllist[index] = (struct all_information*)malloc(sizeof(struct all_information));
        L_NULL_DETCET(alllist[index]);

        int len = strlen(entry->d_name)+1;
        memmove(alllist[index]->name,entry->d_name,len);
        alllist[index]->inode = entry->d_ino;

        struct stat* stat_info = (struct stat*)malloc(sizeof(struct stat));
        L_NULL_DETCET(stat_info);

        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", openfile, entry->d_name);

        if(stat(filepath,stat_info)==-1){
            perror("stat error");
            exit(EXIT_FAILURE);
        }

        alllist[index]->stat_info = stat_info;
    }
    closedir(dir);

    /////////////////////////////////////////////paixu///////////////////////////////////////////////
    if(have_t){
        qsort(alllist,number_files,sizeof(struct all_information*),compre_by_time);
    }else{
        qsort(alllist,number_files,sizeof(struct all_information*),compare_by_name_string);
    }
    if(have_r){
        for(int i=0;i<number_files/2;i++){
            struct all_information* temp = alllist[i];
            alllist[i] = alllist[number_files - 1 - i];
            alllist[number_files - 1 - i] = temp;
        }
    }
    /////////////////////////////////////////////打印///////////////////////////////////////////////
    for(int i=0;i<number_files;i++){
    
        if(!have_a){
            if(alllist[i]->name[0]!='.'){
                if(have_i){
                    printf("%d ",alllist[i]->inode);
                }
                if(have_s){
                    printf("%lu ",alllist[i]->stat_info->st_blocks/2);
                }
                if(have_l) l_handle(alllist,i);
                printf("%s ",alllist[i]->name);
                if(have_l){
                    printf("\n");
                }
            }
        }else{
            if(have_i){
                printf("%d ",alllist[i]->inode);
            }
            if(have_s){
                printf("%lu ",alllist[i]->stat_info->st_blocks/2);
            }
            if(have_l) l_handle(alllist,i);
            printf("%s ",alllist[i]->name);
            if(have_l){
                printf("\n");
            }
        }
    
        if(!have_l){
            /////////////////////////////////////////////////
            if(i==number_files-1){
                printf("\n");
            }
        }
    }

    if(have_R){
        for(int i=0;i<number_files;i++){
            if(strcmp(alllist[i]->name,".")!=0 && strcmp(alllist[i]->name,"..")!=0 && (have_a || alllist[i]->name[0]!='.')){
                if(S_ISDIR(alllist[i]->stat_info->st_mode)){
                    printf("\n%s:\n",alllist[i]->name);
                    handle(alllist[i]->name,have_a,have_r,have_t,have_R,have_i,have_s,have_l);
                }
            }
        }
    }
    return 0;
}





void l_handle(struct all_information** alllist,int index){
    printf("l_handle ");
};





int count_dir_entry(DIR* dir){

    int count=0;
    struct dirent *entry;

    rewinddir(dir);

    while((entry = readdir(dir)) != NULL){
        count++;
    }

    rewinddir(dir);

    
    return count;
}



















int compare_by_name_string(const void *a,const void *b){
    
    const struct all_information* info1 = *(const struct all_information**)a;
    const struct all_information* info2 = *(const struct all_information**)b;

    return strcmp(info1->name, info2->name);
}

int compre_by_time(const void *a,const void *b){

    const struct all_information* info1 = *(const struct all_information**)a;
    const struct all_information* info2 = *(const struct all_information**)b;

    if(info1->stat_info->st_mtime < info2->stat_info->st_mtime) return 1;
    else if(info1->stat_info->st_mtime > info2->stat_info->st_mtime) return -1;
    else return 0;
}

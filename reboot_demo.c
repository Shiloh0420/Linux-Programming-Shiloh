#include<unistd.h>
#include<linux/reboot.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    
    if(syscall(SYS_reboot,LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2,LINUX_REBOOT_CMD_RESTART,NULL) == -1){

        perror("reboot failed");
        exit(EXIT_FAILURE);

        return 0;
        
    }
}
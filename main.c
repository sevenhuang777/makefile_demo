#include <stdio.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h> /* 定义数据类型，如 ssize_t，off_t等 */
#include <unistd.h> /* 定义read，write，close，lseek lseeklseek等函数原型 */
#include <errno.h> /* 与全局变量errno相关的定义 */
#include <fcntl.h> /*  定义open,creat等函数原型，创建文件权限的符号常量 等函数原型，创建文件权限的符号常量 S_IRUSRS_IRUSRS_IRUSRS_IRUSR 等 */
#include <pthread.h>

#include "debug.h"
#include "syscode.h"

int test_fun(int a)
{
	if(a == 0) return SUCCESS;
	else goto exit;
exit:
    return ERROR;
}

int main(int argc, char* argv[])
{
    char sz_str[]="Hello, welcome to linux world!";
    int rv;

	debug_level_init(INFO_LEVEL|WAR_LEVEL|ERR_LEVEL);
	system_log_fd_open();
	system_log_info_save("haha %d\n", 48);
	system_log_info_save("system log test line 1\n");
	system_log_info_save("system log test line 2\n");
	system_log_fd_close();

	system_log_fd_open();
	system_log_info_save("system log test line 3\n");
	system_log_fd_close();
    //char sz_filename[]="hello.txt";
	//int fd = -1;
	//fd = open(sz_filename, 0x664 | O_WRONLY);
    //if(fd < 0)
	//    perror("open error");

	//rv = 0;
    //rv = write(fd, sz_str, sizeof(sz_str));
	//if(rv == -1) {
	//	perror("write error");
    //}

	//close(fd);
	//CALL(test_fun,(0));
	//log_level_dump();
    //printf("%d \n", sizeof(long long));
    //LOG_INFO("haha %d\n", 48);
    //LOG_WAR("haha %d\n", 48);
	//LOG_ERR("haha %d\n", 48);

    
}
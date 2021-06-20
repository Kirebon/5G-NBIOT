#include <stdio.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sqlite3.h>

int main()
{
	int fd = 0;
	int ret = 0;
	fd = socket(AF_INET, SOCK_STREAM, 0); 
	if(fd < 0) {
	perror("socket");
		return 1;
	} 

	

	struct sockaddr_in dst;
	dst.sin_family = AF_INET;
	dst.sin_port = htons(12222);
	dst.sin_addr.s_addr = inet_addr("1.116.177.134");
	
	ret = connect(fd, &dst, 16);
	if(ret < 0) {
		perror("connect");
		return 1;
	} 
	while(1){
		unsigned char data[1024] = {0};
		ret = recv(fd, data, 1024, 0); 
		if(ret < 0) {
			perror("recv");
			return 1;
		}
		char *a[255];
		char *m = "update nbiot set data = ";
		char *n = "where number = 1";
		sprintf(a,"%s%s%s%s%s",m,"\"",data,"\"",n);
		sqlite3 *db;
		ret = sqlite3_open("/home/kernel/nbiot",&db);
		if(ret!=SQLITE_OK){
			printf("sqlite3 open error\n");
			exit(1);
		}
	 	char *pErrMsg;	
		/*ret = sqlite3_exec(db,c,0,0,&pErrMsg);
		if(ret!=SQLITE_OK){
			printf("sqlite3 exec error\n");
			sqlite3_close(db);
			exit(1);
		}*/

		if(data !=NULL){
				ret = sqlite3_exec(db,a,0,0,&pErrMsg);
				if(ret!=SQLITE_OK){
				printf("sqlite3 exec error\n");
			}
		}
	}
}

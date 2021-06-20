#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sqlite3.h>

int myfunc(void *p,int argc,char **argv,char **argvv){
	int i;
	*(int *)p = 0;
	for(i=0;i<argc;i++){
		//printf("%s\n = %s",argvv[i],argv[i]?argv[i]:"NULL");
		//printf("%s",argv[i]?argv[i]:"NULL");
		//printf("%s",argv[i]);
		char *ww = argv[i];
		printf(ww);
		printf("\n");
	}
	printf("\n");
	return 0;
}

int main(){
	while(1){
	printf("Content-type: text/html;charset=UTF-8\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>物联网环境监测</title>\n");
	printf("<meta http-equiv='refresh' content='1' charset=UTF-8>");
	printf("</head>\n");
	//printf("<body background=../icons/nine.jpg>");
	printf("<body style=\"background:linear-gradient(to right, #000000,#708090);\"");
	//printf("<body background: url(../nine.jpg) no-repeat center top;");
	printf("<html>\n");
	printf("<table cellpadding='20'>" );
	printf("<h1> <font color=white size=20>物联网实时监测系统 </h1>");

	sqlite3 *db;
	char *err = 0;
	int ret = 0;
	int empty = 1;
	time_t t;
	struct tm * timeinfo;
	time(&t);
	timeinfo = localtime(&t);

	
		ret = sqlite3_open("/nbiot",&db);
		if(ret!=SQLITE_OK){
			printf("sqlite3 open error\n");
			exit(1);
		}
		ret = sqlite3_exec(db,"select * from nbiot",myfunc,&empty,&err);
		if(ret!=SQLITE_OK){
			printf("sqlite3 exec error\n");
			sqlite3_close(db);
			exit(1);
		}
 	
	printf("<tr>");
	printf("<td>");
	//printf("<font color=white size=100>当前温度：%s度</font>",data);
	printf("</td>");
	printf("</tr>");

	printf("<tr>");
    printf("<td>");
    //printf("<font color=white size=100>当前湿度：%s%</font>",data);
    printf("</td>");
    printf("</tr>");

	printf("<tr>");
	printf("<td>");
	
	printf ("<Font color=white size=100>时间： %s </Font>",asctime(timeinfo) );
	printf("</td>");
	printf("</tr>");
	printf("</table>");

	printf("</body>");
	printf("</html>\n");
	return 0;}
}


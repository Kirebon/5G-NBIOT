#include <stdio.h>
#include <mysql/mysql.h>
#include <time.h>
int main(){
	time_t t;
	struct tm * timeinfo;
	time(&t);
	timeinfo = localtime ( &t );
	MYSQL tmp;
	MYSQL *my = NULL;
	my = mysql_init(&tmp);
	int *ret = NULL;

	ret = mysql_real_connect(my, "localhost", "root", "MzYj@123456", "nbiot", 0, NULL,0); 
	if(ret == NULL) {
		printf("mysql real connect error\n");
	return 1;
	}

	char *sql = "select * from nbiot";
	int value = 0;
	value = mysql_query(my, sql);

	if(value != 0) {
		printf("mysql query\n");
	return 1;
	} 

	MYSQL_RES *res = NULL;
	res = mysql_store_result(my);
	MYSQL_ROW row;
	row = mysql_fetch_row(res);
 
 
	printf("Content-type: text/html;charset=UTF-8\n\n");
	printf("<html>\n");
	printf("<head>\n");
			printf("<title>物联网环境监测</title>\n");
	printf("<meta http-equiv='refresh' content='1' charset=UTF-8>");
	printf("</head>\n");
	//printf("<body background=/icons/nine.jpg>");
	printf("<body style=\"background:linear-gradient(to right, #00ffff,#800080,#ff0000);\"");
	printf("<html>\n");
			printf("<table cellpadding='20' text-align='center'> " );
			printf("<h1> <font color=white size=20><center> 物联网实时监测系统 </h1>");
 
	printf("<tr>");
	printf("<td>");
	printf("<font color=white size=100 ><center>%s",row[1]);
	printf("</td>");
	printf("</tr>");
	printf("<tr>");
	printf("<td>");
	printf ("<Font color=white size=100><center> 时间： %s ",asctime(timeinfo) );
	printf("</td>");
	printf("</tr>");
	printf("</table>");
	printf("</body>");
	printf("</html>\n");
	return 0;
	}


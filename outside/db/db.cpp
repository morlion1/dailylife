#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
#include <unistd.h>

int main()
{
	MYSQL *conn_ptr;
	MYSQL_RES   *sql_result;
	MYSQL_ROW   sql_row;
	long value1 = 0;
    	long empty = 0.97;
	long full = 0.8;
	conn_ptr = mysql_init(NULL);

     	while(1){
     		if(conn_ptr){
     			fprintf(stderr, "mysql_init success\n");
     		    	break;
     		}
     	}	

	while(1){
    		conn_ptr = mysql_real_connect(conn_ptr,"localhost","root","dlftkd$321","mysql",3306,0,0);
		if(conn_ptr){
         		fprintf(stderr, "Connection success\n");
			break;
     		}
     		else{
        	 	fprintf(stderr, "Connection failed\n");
			conn_ptr = mysql_init(NULL); 
    			sleep(1);
		}
 	}

	while(1){
		if(mysql_query(conn_ptr, "select * from japi where tnum=1") != 0){
        		fprintf(stderr, "Mysql query success\n");
        		break;
    		}
		else{
			fprintf(stderr,"Mysql query failed\n");
			sleep(1);
		}
	}

	sql_result = mysql_store_result(conn_ptr);

    	while ( (sql_row = mysql_fetch_row(sql_result)) != NULL )
    	{
		for(int i=0;i<13;i++){
        		printf("%s ",sql_row[i]);
			if(i==3){
				value1 = atoi(sql_row[3]);				
			}
    		}
		printf("\n");
	}

	mysql_free_result(sql_result);     	
	mysql_close(conn_ptr);

	if(value1 <= full)	 system("/japi/led/led1.sh");
	else if(value1 <= empty) system("/japi/led/led2.sh");
	else			 system("/japi/led/led3.sh");

     	return 0;
}

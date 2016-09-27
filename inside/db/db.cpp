#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
#include <unistd.h>

using namespace std;
#define MAX_SIZE 1000

int main()
{
	MYSQL *conn_ptr;
	MYSQL_RES   *sql_result;
	MYSQL_ROW   sql_row;

    	conn_ptr = mysql_init(NULL);

	char query[255];
	int tnum = 1;
	int tcount = 1;
	int pos = 1;
	char value1[MAX_SIZE];
	string temp;
	int query_return;	

     	while(1){
     		if(conn_ptr){
     			fprintf(stderr, "mysql_init success\n");
     		    	break;
     		}
     	}	

	while(1){
    		conn_ptr = mysql_real_connect(conn_ptr,"192.168.10.103","root","dlftkd$321","mysql",3306,0,0);
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
	ifstream File("/japi/db/temp");
        File.getline(value1, 100);
	cout << "file read done" << endl;
	File.close();	
    	
	sprintf(query, "update japi set tcount=%d, pos=%d, value1=%s where tnum = %d",tcount, pos, value1, tnum);
	
	while(1){
		query_return = mysql_query(conn_ptr, query);
    		if (query_return == 0)
    		{
        		fprintf(stderr, "query done\n");
        		break;
    		}
		else{
			fprintf(stderr, "query error\n");
			sleep(1);
		}
	}


	mysql_close(conn_ptr);

     	return 0;
}

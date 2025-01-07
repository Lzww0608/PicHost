#include "db_pool.h"
#include <string.h>
#include <map>
#include <string>
#include <mysql/mysql.h>

#define MIN_DB_CONN_CNT 1
#define MAX_DB_CONN_FAIL_NUM 10


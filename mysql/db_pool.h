#ifndef DBPOOL_H_
#define DBPOOL_H_

#include <mysql/mysql.h>


#define MAX_ESCAPE_STRING_LEN 10240


using namespace std;

// 返回结果 select的时候用
class CResultSet {
public:
    CResultSet(MYSQL_RES *res);
    virtual ~CResultSet();

    bool Next();
    int GetInt(const char *key);
    char *GetString(const char *key);

private:
    int _GetIndex(const char *key);
    // 该结构代表返回行的查询结果（SELECT, SHOW, DESCRIBE, EXPLAIN）
    MYSQL_RES *res_;
    // 这是1行数据的“类型安全”表示。它目前是按照计数字节字符串的数组实施的。
    MYSQL_ROW row_;
    map<string, int> key_map_;
}


#endif
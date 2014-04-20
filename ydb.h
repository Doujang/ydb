#ifndef PHP_YDB_H
#define PHP_YDB_H

#include "php.h"
#include "zend_extensions.h"

#define YDB_NAME       "ydb"
#define YDB_VERSION    "0.5"
#define YDB_AUTHOR     "lizhonghua"
#define YDB_COPYRIGHT  "Copyright (c) 2013-2014 by lizhonghua"
#define YDB_COPYRIGHT_SHORT "Copyright (c) 2013-2014"
#define YDB_URL        "http://ydb.org"
#define YDB_URL_FAQ    "http://ydb.org/docs/faq#api"

#if(PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 3)

#define MAKE_COPY_ZVAL(ppzv, pzv) \
		*(pzv) = **(ppzv);            \
zval_copy_ctor((pzv));        \
INIT_PZVAL((pzv));

#endif

#define true 1
#define false 0

#define INIT_HASH_SIZE 15

#define MAX_PARAMS_LEN 100
#define MAX_NEWVAR_LEN 1000
#define MAX_KEY_LEN 100
#define MAX_URL_LEN 1000

#define DIR_MAX_LEN 200

#define YDB_LOG_FILE "/log/ydbinfo.log"

#define CURL_RES_FIRST_LINE "HTTP/1.1 200 OK"
#define CURL_RES_FLAG_HEADER "YDB-YDB : 1"

#define MAX_HEAD_LINE_LEN 200

ZEND_BEGIN_MODULE_GLOBALS (ydb)

        int is_look_variable;			//�Ƿ�鿴����ֵ
        int is_timer;					//�Ƿ��ʱ
        int is_net_timer;				//�Ƿ������������м�ʱ
        char *ydb_cur_classname;		//��ǰִ��λ�ڵ���
        char *ydb_cur_funname;			//��ǰִ��λ�ڵĺ���

        HashTable *dst_symbol_table;
        zend_op_array *ydb_cur_op_array;	//��ǰִ�к�����op_array
        zend_op_array *ydb_dst_op_array;	// Ҫִ�й۲�ĺ���op_array

        char *input_classname;			//���������
        char *input_funname;			//����ĺ�����
        char *input_varname;			//����ı�����
        char *input_new_var;			//������±���ֵ
        HashTable *ydb_varn;			//��ű���ֵ

        int ydb_shouldreturn;

        int is_post;					//�Ƿ���post����
        char input_post_classname[MAX_PARAMS_LEN];
        char input_post_funname[MAX_PARAMS_LEN];
        char input_post_varname[MAX_PARAMS_LEN];
        char input_post_newvar[MAX_NEWVAR_LEN];

        char *parent_classname;
        char *parent_funname;

        zend_op_array *timer_op_array;

        struct timeval start, start_sum;	//��ʱ��ʼʱ��
        struct timeval end, end_sum;	//��ʱ����ʱ��

        int usetimer;
        int is_sum_time_begin;			//�Ƿ�ʼ�ܼ�ʱ
        int ydb_timer;

        HashTable *timer_fun;			//��ź�����ʱֵ

        int uselog;						//�Ƿ�ʹ����־��¼���

        int is_get_debug_params;		//�Ƿ��Ѿ�����˵��Բ���

        HashTable *input_vars;			//����ı�������
        int is_set_new_var;				// �Ƿ��Ѹ����˱���

        void (*orig_curl_init) (INTERNAL_FUNCTION_PARAMETERS);
        void (*orig_curl_setopt) (INTERNAL_FUNCTION_PARAMETERS);
        void (*orig_curl_exec) (INTERNAL_FUNCTION_PARAMETERS);

        HashTable *key_count;			// ��ͬkey�ļ���

        int is_replace_new_fun;			//�Ƿ����滻���º���handler
        int is_get_remote_res;			//�Ƿ�ӱ����ö˻���˽��

        char *old_curl_url;
        char new_curl_url[MAX_URL_LEN];

        char *curl_res;					// curl���صĽ��,����ͷ��

        int is_send_header;				//�Ƿ��Ѿ�������ydbͷ��

        int is_dump_code;				//�Ƿ��ӡִ�д���
        int is_get_code_info;			//�Ƿ�����ִ�д������Ϣ
        char *file_name;				//�ļ���
        int line_start;					//��ʼ��
        int line_end;					//������

        int depth;						//Զ�̷������

ZEND_END_MODULE_GLOBALS (ydb)

	ZEND_DECLARE_MODULE_GLOBALS (ydb)
#ifdef ZTS
#define YG(v) TSRMG(ydb_globals_id, zend_ydb_globals *, v)
#else
#define YG(v) (ydb_globals.v)
#endif
#endif

/**
 * @file   type.h
 * @author mathslinux <riegamaths@gmail.com>
 * @date   Sun May 20 22:24:30 2012
 * 
 * @brief  Linux WebQQ Data Struct API
 * 
 * 
 */

#ifndef LWQQ_TYPE_H
#define LWQQ_TYPE_H

#include "queue.h"

/************************************************************************/
/* Struct defination */

typedef struct LwqqFriendCategory {
    int index;
    int sort;
    char *name;
    LIST_ENTRY(LwqqFriendCategory) entries;
} LwqqFriendCategory;

/* QQ buddy */
typedef struct LwqqBuddy {
    char *uin;                  /**< Uin. Change every login */
    char *qqnumber;             /**< QQ number */
    int vip_info;
    char *nick;
    char *markname;

    char *face;
    char *flag;

    int cate_index;             /**< Index of the category */

    /*
     * 1 : Desktop client
     * 21: Mobile client
     * 41: Web QQ Client
     */
    int client_type;
    LIST_ENTRY(LwqqBuddy) entries;
} LwqqBuddy;

typedef struct LwqqVerifyCode {
    char *str;
    char *type;
    char *img;
} LwqqVerifyCode ;

/* LwqqClient API */
typedef struct LwqqClient {
    char *username;             /**< Username */
    char *password;             /**< Password */
    LwqqBuddy *myself;          /**< Myself */
    char *version;              /**< WebQQ version */
    LwqqVerifyCode *vc;          /**< Verify Code */
    char *ptvfsession;          /**< ptvfsession */
    char *ptcz;
    char *skey;
    char *ptwebqq;
    char *ptuserinfo;
    char *uin;
    char *ptisp;
    char *pt2gguin;
    char *clientid;
    char *seskey;
    char *cip;
    char *index;
    char *port;
    char *status;
    char *vfwebqq;
    char *psessionid;
    char *cookie;
    LIST_HEAD(, LwqqBuddy) friends; /**< QQ friends */
    LIST_HEAD(, LwqqFriendCategory) categories; /**< QQ friends categories */
} LwqqClient;

/* Lwqq Error Code */
typedef enum {
    LWQQ_OK,
    LWQQ_ERROR,
    LWQQ_LOGIN_NEED_VC = 10,
    LWQQ_NETWORK_ERROR = 20,
    LWQQ_HTTP_ERROR = 99,
} LwqqErrorCode;

/* Struct defination end */

/************************************************************************/
/* LwqqClient API */
/** 
 * Create a new lwqq client
 * 
 * @param username QQ username
 * @param password QQ password
 * 
 * @return A new LwqqClient instance, or NULL failed
 */
LwqqClient *lwqq_client_new(const char *username, const char *password);

/** 
 * Free LwqqClient instance
 * 
 * @param client LwqqClient instance
 */
void lwqq_client_free(LwqqClient *client);

/* LwqqClient API end */

/************************************************************************/
/* LwqqBuddy API  */
/** 
 * 
 * Create a new buddy
 * 
 * @return A LwqqBuddy instance
 */
LwqqBuddy *lwqq_buddy_new();

/** 
 * Free a LwqqBuddy instance
 * 
 * @param buddy 
 */
void lwqq_buddy_free(LwqqBuddy *buddy);

/** 
 * Find buddy object by buddy's uin member
 * 
 * @param lc Our Lwqq client object
 * @param uin The uin of buddy which we want to find
 * 
 * @return 
 */
LwqqBuddy *lwqq_buddy_find_buddy_by_uin(LwqqClient *lc, const char *uin);

/* LwqqBuddy API END*/

/************************************************************************/

#endif  /* LWQQ_TYPE_H */

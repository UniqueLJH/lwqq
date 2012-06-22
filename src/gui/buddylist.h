/**
 * @file   buddylist.h
 * @author mathslinux <riegamaths@gmail.com>
 * @date   Sat Jun 23 02:29:09 2012
 * 
 * @brief  This file is based on gtkqq written by HuangCongyu
 * Inherit from GtkTreeView
 * Used to show the groups and recent contancts
 * 
 */

#ifndef LWQQ_BUDDYLIST_H
#define LWQQ_BUDDYLIST_H

#include <gtk/gtk.h>

/* FIXME */
typedef struct QQGMember {
    GString *uin;
    GString *qqnumber;
    GString *nick;
    GString *flag;
    GString *status;
    GString *card;
    GString *client_type;
} QQGMember;

typedef struct QQGroup {
    GString *name;
    GString *gid;
    GString *gnumber;
    GString *code;
    GString *flag;
    GString *owner;
    GString *mark;
    GString *mask;
    GString *option;
    GString *createtime;
    GString *gclass;
    GString *level;
    GString *face;

    GString *memo;
    GString *fingermemo;

    GPtrArray *members;
} QQGroup;

#define QQ_TYPE_BUDDY_LIST (qq_buddy_list_get_type())
#define QQ_BUDDY_LIST(obj)                                              \
    (G_TYPE_CHECK_INSTANCE_CAST((obj), QQ_TYPE_BUDDY_LIST, QQBuddyList))
#define QQ_IS_BUDDY_LIST(obj)                               \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj, QQ_TYPE_BUDDY_LIST)))
#define QQ_BUDDY_LIST_CLASS(klass)                                      \
    (G_TYPE_CHECK_CLASS_CAST((klass), QQ_TYPE_BUDDY_LIST, QQBuddyListClass))
#define QQ_IS_BUDDY_LIST_CLASS(klass)                   \
    (G_TYPE_CHECK_CLASS_TYPE((klass), QQ_TYPE_BUDDY_LIST))
#define QQ_BUDDY_LIST_GET_CLASS(obj)                                    \
    (G_TYPE_INSTANCE_GET_CLASS((obj), QQ_TYPE_BUDDY_LIST, QQBuddyListClass))

/* List store columns */
enum{
    BDY_LIST_TYPE = 0,      // GDK_TYPE_PIXBUF, client type image
    BDY_LIST_IMG,           // GDK_TYPE_PIXBUF, face image
    BDY_LIST_UIN,           // G_TYPE_STRING, buddy uin or group code
    BDY_LIST_CLASS,         // G_TYPE_INT, buddy or group. 1: buddy, 2:group
                            // 3: group member
    BDY_LIST_NAME,          // G_TYPE_STRING, buddy markname or group name
    BDY_LIST_LNICK,         // G_TYPE_STRING, buddy long nick 
    BDY_LIST_NUMBER,        // G_TYPE_STRING, qq number of the group number
                            // or group fingermemo
    BDY_LIST_COLUMNS        // column number
};

typedef struct __QQBuddyList QQBuddyList;
typedef struct __QQBuddyListClass QQBuddyListClass;

struct __QQBuddyList{
    GtkTreeView parent;
};

struct __QQBuddyListClass{
    GtkTreeViewClass parent;
};

GType qq_buddy_list_get_type();
GtkWidget * qq_buddy_list_new();

//
// Add qq buddy , qq group and qq group member
//
#if 0
void qq_buddy_list_add_buddy(GtkWidget *widget, QQBuddy *bdy);
void qq_buddy_list_add_group(GtkWidget *widget, QQGroup *grp);
void qq_buddy_list_add_group_member(GtkWidget *widget, QQGMember *gm);
#endif

//
// Add multiple buddies and groups and group members
//
void qq_buddy_list_add_buddies(GtkWidget *widget, GPtrArray *bdies);
void qq_buddy_list_add_groups(GtkWidget *widget, GPtrArray *grps);
void qq_buddy_list_add_group_members(GtkWidget *widget, GPtrArray *gms);

//
// Update the information of the qq buddy and qq group and member
//
#if 0
void qq_buddy_list_update_buddy_info(GtkWidget *widget, QQBuddy *bdy);
void qq_buddy_list_update_group_info(GtkWidget *widget, QQGroup *grp);
void qq_buddy_list_update_group_member_info(GtkWidget *widget, QQGMember *gm);
#endif

//
// Update buddies and groups info and group members
//
void qq_buddy_list_update_buddies_info(GtkWidget *widget, GPtrArray *bdies);
void qq_buddy_list_update_groups_info(GtkWidget *widget, GPtrArray *grps);
void qq_buddy_list_update_group_members_info(GtkWidget *widget, GPtrArray *gms);

#endif

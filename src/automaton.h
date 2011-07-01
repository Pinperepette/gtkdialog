#ifndef AUTOMATON_H
#define AUTOMATON_H

#define _GN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "gtkdialog.h"
#include "stack.h"
#include "attributes.h"
#include "stringman.h"
#include "main.h"


typedef int token;

typedef struct _instruction {
	token      command;
	char      *argument;
	gint       ival;
	tag_attr  *tag_attributes;
} instruction;

typedef struct actioncommand {
  GtkWidget   *source_widget;
  char        *destination_name;
} actioncommand;

/*                                -- Type of widget      */
/*                              xxxxxxxx                 */
#define WIDGET_TYPE           0x00FF0000
#define WIDGET_LABEL          0x00010000
#define WIDGET_ENTRY          0x00020000
#define WIDGET_EDIT           0x00030000
#define WIDGET_BUTTON         0x00040000
#define WIDGET_CHECKBOX       0x00050000
#define WIDGET_RADIO          0x00060000
#define WIDGET_LIST           0x00070000
#define WIDGET_TABLE          0x00080000
#define WIDGET_COMBO          0x00090000
#define WIDGET_OKBUTTON       0x000A0000
#define WIDGET_CANCELBUTTON   0x000B0000
#define WIDGET_HELPBUTTON     0x000C0000
#define WIDGET_NOBUTTON       0x000D0000
#define WIDGET_YESBUTTON      0x000E0000
#define WIDGET_SCROLLEDW      0x000F0000
#define WIDGET_VBOX           0x00100000
#define WIDGET_HBOX           0x00200000
#define WIDGET_FRAME          0x00300000
#define WIDGET_NOTEBOOK       0x00310000
#define WIDGET_WINDOW         0x00400000
#define WIDGET_PIXMAP         0x00500000
#define WIDGET_MENUBAR        0x00600000
#define WIDGET_MENU           0x00700000
#define WIDGET_MENUITEM       0x00800000
#define WIDGET_GVIM           0x00900000
#define WIDGET_TREE           0x00A00000
#define WIDGET_CHOOSER        0x00A10000
#define WIDGET_MENUSEP        0x00A20000
#define WIDGET_PROGRESS       0x00A30000
#define WIDGET_HSEPARATOR     0x00A40000
#define WIDGET_VSEPARATOR     0x00A50000
#define WIDGET_COMBOBOXTEXT   0x00A60000

/*
 * Imperative stuff.
 */
#define VARIABLE_NAME         0x00010000
#define CONST_NUMBER          0x00020000
#define OP_ADD                0x000a0000
#define OP_SUBST              0x000b0000
#define OP_MULT               0x000c0000
#define OP_DIV                0x000d0000
#define REL_EQ                0x00100000
#define REL_NE                0x00200000



/*                                   - Widget subtype    */
/*                              xxxxxxxx                 */
#define WIDGET_SUBTYPE        0x00000F00
/*                                  - Command            */
/*                              xxxxxxxx                 */
#define COMMAND               0x0000F000
#define PUSH                  0x00001000
#define SUM                   0x00002000
#define SET                   0x00003000
#define SHOW		      0x00004000
#define IFNGOTO               0x00005000
#define IMPUSH                0x00006000
#define IMASSG                0x00007000
#define GOTO                  0x00008000

/*                                    -- Attribute           */
/*                              xxxxxxxx                 */
#define ATTRIBUTE             0x000000ff
#define ATTR_LABEL            0x00000001
#define ATTR_DEFAULT          0x00000002
#define ATTR_VARIABLE         0x00000003
#define ATTR_HEIGHT           0x00000004
#define ATTR_WIDTH            0x00000005
#define ATTR_INPUT            0x00000006
#define ATTR_VISIBLE          0x00000007
#define ATTR_ACTION           0x00000008
#define ATTR_ITEM             0x00000009
#define ATTR_OUTPUT           0x0000000A
#define ATTR_SOCKET           0x0000000B


/*                               - Sub attribute         */
/*                              xxxxxxxx                 */
#define SUB_ATTRIBUTE         0x0F000000
#define SUB_ATTR_SHELL        0x01000000
#define SUB_ATTR_FILE         0x02000000

#if 0
#define SUB_ATTR_CLEAR        0x03000000
#define SUB_ATTR_APPEND       0x04000000
#define SUB_ATTR_EXIT         0x05000000
#define SUB_ATTR_FILESEL      0x0A000000
#define SUB_ATTR_REMOVE       0x0B000000
#define SUB_ATTR_REFRESH      0x0C000000
#define SUB_ATTR_LAUNCH       0x0D000000
#endif


/*************************************************************************
 * Public functions:                                                     *
 *                                                                       *
 *                                                                       *
 *************************************************************************/
gint window_delete_event_handler(
		GtkWidget * widget, 
		GtkWidget *event, 
		gpointer data);
stackelement _sum( stackelement a, stackelement b);
void fileselection_made( GtkWidget *w, actioncommand *action );

void button_pressed(GtkWidget *, const gchar *);

int token_store(token command);
int token_store_attr(token command, tag_attr *attributes);
int token_store_with_argument_attr(token command, const char *argument, tag_attr *attributes);
int token_store_with_argument( token command, const char *argument);

gboolean token_store_with_tag_attributes(token command, GList *attr);
gint instruction_get_pc(void);
void instruction_set_jump(gint from, gint where);

void on_any_widget_changed_event(GtkWidget *widget, AttributeSet  *Attr);

#endif

/*
 * signals.c:
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  László Pere <pipas@linux.pte.hu>
 * Copyright (C) 2011-2012  Thunor <thunorsif@hotmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Includes */
#define _GNU_SOURCE
#include <gtk/gtk.h>
#include "config.h"
#include "gtkdialog.h"
#include "attributes.h"
#include "signals.h"
#include "tag_attributes.h"
#include "widgets.h"
#if HAVE_VTE
#include <vte/vte.h>
#endif
#if HAVE_SYS_INOTIFY_H
#include <sys/inotify.h>
#endif

/* Defines */
//#define DEBUG_CONTENT
//#define DEBUG_TRANSITS

/* Local function prototypes */
gboolean widget_signal_executor_eval_prefix(gchar **command, gint is_active);

/* Notes: */

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_clicked_attr(GtkWidget *button, AttributeSet *Attr)
{
/*	GList *element;	Redundant
	gchar *command;
	gchar *signal;
	gchar *type; */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(button, Attr, "clicked");

/* Redundant
	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {

#ifdef DEBUG_CONTENT
		GList *attr;
		Attribute *data;
		attr = g_list_first(Attr->attr[ATTR_ACTION]);
		while (attr) {
			data = attr->data;
			printf("%s: BEFORE: element=%p attr->data->text='%s'\n",
				__func__, element, data->text);
			attr = g_list_next(attr);
		}
#endif

		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal != NULL && g_ascii_strcasecmp(signal, "clicked") != 0) {
		} else {
			execute_action(button, command, type);
		}

#ifdef DEBUG_CONTENT
		attr = g_list_first(Attr->attr[ATTR_ACTION]);
		while (attr) {
			data = attr->data;
			printf("%s:  AFTER: element=%p attr->data->text='%s'\n",
				__func__, element, data->text);
			attr = g_list_next(attr);
		}
#endif

		command = attributeset_get_next(&element, Attr, ATTR_ACTION);

#ifdef DEBUG_CONTENT
		printf("%s: element=%p\n", __func__, element);
#endif
	} */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_entered_attr(GtkWidget *button, AttributeSet *Attr)
{
/*	GList *element;	Redundant
	gchar *command;
	gchar *signal;
	gchar *type; */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(button, Attr, "enter");

/* Redundant
	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "enter") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	} */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_leaved_attr(GtkWidget *button, AttributeSet *Attr)
{
/*	GList *element;	Redundant
	gchar *command;
	gchar *signal;
	gchar *type; */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(button, Attr, "leave");

/* Redundant
	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "leave") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	} */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

/* Thunor: create_chooser() is now the only function calling this */

void button_pressed(GtkWidget *button, const gchar *str)
{
	execute_action(GTK_WIDGET(button), str, NULL);
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_pressed_attr(GtkWidget *button, AttributeSet *Attr)
{
/*	GList *element;	Redundant
	gchar *command;
	gchar *signal;
	gchar *type; */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(button, Attr, "pressed");

/* Redundant
	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "pressed") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	} */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void button_released_attr(GtkWidget *button, AttributeSet *Attr)
{
/*	GList *element;	Redundant
	gchar *command;
	gchar *signal;
	gchar *type; */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(button, Attr, "released");

/* Redundant
	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL) {
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "released") != 0) {
		} else {
			execute_action(button, command, type);
		}
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	} */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_activate_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "activate");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_button_pressed(GtkWidget *widget,
	GdkEventButton *event, AttributeSet *Attr)
{
	gchar *ptrx = g_strdup_printf("%.0f", event->x);
	gchar *ptry = g_strdup_printf("%.0f", event->y);
	gchar *ptrmod = g_strdup_printf("%u", event->state);
	gchar *button = g_strdup_printf("%u", event->button);
	gchar *ptrbtn = g_strdup_printf("%u", event->button);
	gchar *ptrxroot = g_strdup_printf("%.0f", event->x_root);
	gchar *ptryroot = g_strdup_printf("%.0f", event->y_root);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_setenv("PTR_X", ptrx, TRUE);
	g_setenv("PTR_Y", ptry, TRUE);
	g_setenv("PTR_MOD", ptrmod, TRUE);
	g_setenv("BUTTON", button, TRUE);	/* Deprecated */
	g_setenv("PTR_BTN", ptrbtn, TRUE);
	g_setenv("PTR_X_ROOT", ptrxroot, TRUE);
	g_setenv("PTR_Y_ROOT", ptryroot, TRUE);

	widget_signal_executor(widget, Attr, "button-press-event");

	g_unsetenv("PTR_X");
	g_unsetenv("PTR_Y");
	g_unsetenv("PTR_MOD");
	g_unsetenv("BUTTON");
	g_unsetenv("PTR_BTN");
	g_unsetenv("PTR_X_ROOT");
	g_unsetenv("PTR_Y_ROOT");
	g_free(ptrx);
	g_free(ptry);
	g_free(ptrmod);
	g_free(button);
	g_free(ptrbtn);
	g_free(ptrxroot);
	g_free(ptryroot);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_button_released(GtkWidget *widget,
	GdkEventButton *event, AttributeSet *Attr)
{
	gchar *ptrx = g_strdup_printf("%.0f", event->x);
	gchar *ptry = g_strdup_printf("%.0f", event->y);
	gchar *ptrmod = g_strdup_printf("%u", event->state);
	gchar *button = g_strdup_printf("%u", event->button);
	gchar *ptrbtn = g_strdup_printf("%u", event->button);
	gchar *ptrxroot = g_strdup_printf("%.0f", event->x_root);
	gchar *ptryroot = g_strdup_printf("%.0f", event->y_root);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_setenv("PTR_X", ptrx, TRUE);
	g_setenv("PTR_Y", ptry, TRUE);
	g_setenv("PTR_MOD", ptrmod, TRUE);
	g_setenv("BUTTON", button, TRUE);	/* Deprecated */
	g_setenv("PTR_BTN", ptrbtn, TRUE);
	g_setenv("PTR_X_ROOT", ptrxroot, TRUE);
	g_setenv("PTR_Y_ROOT", ptryroot, TRUE);

	widget_signal_executor(widget, Attr, "button-release-event");

	g_unsetenv("PTR_X");
	g_unsetenv("PTR_Y");
	g_unsetenv("PTR_MOD");
	g_unsetenv("BUTTON");
	g_unsetenv("PTR_BTN");
	g_unsetenv("PTR_X_ROOT");
	g_unsetenv("PTR_Y_ROOT");
	g_free(ptrx);
	g_free(ptry);
	g_free(ptrmod);
	g_free(button);
	g_free(ptrbtn);
	g_free(ptrxroot);
	g_free(ptryroot);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_changed_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_color_set_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "color-set");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_font_set_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "font-set");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_configure_event(GtkWidget *widget,
	GdkEventConfigure *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "configure-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_delete_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "delete-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_destroy_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "destroy-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_enter_notify_event(GtkWidget *widget,
	GdkEventCrossing *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "enter-notify-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_focus_in_event(GtkWidget *widget,
	GdkEventFocus *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "focus-in-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_focus_out_event(GtkWidget *widget,
	GdkEventFocus *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "focus-out-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_hide(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "hide");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

#if GTK_CHECK_VERSION(2,16,0)
/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_icon_press_event(GtkWidget *widget,
	GtkEntryIconPosition pos, GdkEvent *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (pos == GTK_ENTRY_ICON_PRIMARY)
		widget_signal_executor(widget, Attr, "primary-icon-press");
	else
		widget_signal_executor(widget, Attr, "secondary-icon-press");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_icon_release_event(GtkWidget *widget,
	GtkEntryIconPosition pos, GdkEvent *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	if (pos == GTK_ENTRY_ICON_PRIMARY)
		widget_signal_executor(widget, Attr, "primary-icon-release");
	else
		widget_signal_executor(widget, Attr, "secondary-icon-release");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}
#endif

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_child_exited_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if HAVE_VTE
	if (VTE_IS_TERMINAL(widget)) {
		/* The pid will now be invalid so set widget's variable to 0 */
		g_object_set_data(G_OBJECT(widget), "_pid", (gpointer)0);
	}
#endif

	widget_signal_executor(widget, Attr, "child-exited");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_key_press_event(GtkWidget *widget,
	GdkEventKey *event, AttributeSet *Attr)
{
	gchar *keyval = g_strdup_printf("0x%03x", event->keyval);
	gchar *keysym = g_strdup(gdk_keyval_name(event->keyval));
	gchar *keyuni = g_strdup_printf("%lc", gdk_keyval_to_unicode(event->keyval));
	gchar *keymod = g_strdup_printf("%u", event->state);
	gchar *keyraw = g_strdup_printf("0x%x", event->hardware_keycode);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_setenv("KEY_VAL", keyval, TRUE);
	g_setenv("KEY_SYM", keysym, TRUE);
	g_setenv("KEY_UNI", keyuni, TRUE);
	g_setenv("KEY_MOD", keymod, TRUE);
	g_setenv("KEY_RAW", keyraw, TRUE);

	widget_signal_executor(widget, Attr, "key-press-event");

	g_unsetenv("KEY_VAL");
	g_unsetenv("KEY_SYM");
	g_unsetenv("KEY_UNI");
	g_unsetenv("KEY_MOD");
	g_unsetenv("KEY_RAW");
	g_free(keyval);
	g_free(keysym);
	g_free(keyuni);
	g_free(keymod);
	g_free(keyraw);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_key_release_event(GtkWidget*widget,
	GdkEventKey *event, AttributeSet *Attr)
{
	gchar *keyval = g_strdup_printf("0x%03x", event->keyval);
	gchar *keysym = g_strdup(gdk_keyval_name(event->keyval));
	gchar *keyuni = g_strdup_printf("%lc", gdk_keyval_to_unicode(event->keyval));
	gchar *keymod = g_strdup_printf("%u", event->state);
	gchar *keyraw = g_strdup_printf("0x%x", event->hardware_keycode);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	g_setenv("KEY_VAL", keyval, TRUE);
	g_setenv("KEY_SYM", keysym, TRUE);
	g_setenv("KEY_UNI", keyuni, TRUE);
	g_setenv("KEY_MOD", keymod, TRUE);
	g_setenv("KEY_RAW", keyraw, TRUE);

	widget_signal_executor(widget, Attr, "key-release-event");

	g_unsetenv("KEY_VAL");
	g_unsetenv("KEY_SYM");
	g_unsetenv("KEY_UNI");
	g_unsetenv("KEY_MOD");
	g_unsetenv("KEY_RAW");
	g_free(keyval);
	g_free(keysym);
	g_free(keyuni);
	g_free(keymod);
	g_free(keyraw);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_leave_notify_event(GtkWidget *widget,
	GdkEventCrossing *event, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "leave-notify-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_map_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "map-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_realized(GtkWidget *widget, tag_attr *tag_attributes)
{
	variable         *var = find_variable_by_widget(widget);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): widget=%p  tag_attributes=%p\n", __func__,
		widget, tag_attributes);
#endif

	widget_set_tag_attributes(widget, tag_attributes);

	widget_signal_executor(widget, var->Attributes, "realize");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_show(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "show");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_toggled_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "toggled");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean on_any_widget_unmap_event(GtkWidget *widget, GdkEvent *event,
	AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "unmap-event");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_value_changed_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "value-changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_select_row_event(GtkWidget *widget, gint row,
	gint column, GdkEvent *event, gpointer Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): row=%i column=%i\n", __func__, row, column);
#endif

	widget_signal_executor(widget, Attr, "select-row");

/* Redundant.
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

	if (Attr == NULL) return;

	variables_set_row_column(
		attributeset_get_first(&element, Attr, ATTR_VARIABLE),
		row, column);

	/$ Thunor: This code does not support <action signal="type">.
	 * This callback is connected to the "select-row" signal,
	 * therefore if there exists an action directive specifying a
	 * particular signal then that will be executed as well.
	 * 
	 * This widget was in fact deprecated in GTK+ 2.0 anyway $/

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		execute_action(clist, command, type);
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	} */

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_selection_changed_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "selection-changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_row_activated_event(GtkWidget *widget,
	GtkTreePath *path, GtkTreeViewColumn *column, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "row-activated");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/* Redundant
void tree_row_activated_attr(GtkTreeView *tree_view, GtkTreePath *path,
	GtkTreeViewColumn *column, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal != NULL && g_ascii_strcasecmp(signal, "row-activated") != 0)
			goto next_command;
		
		execute_action(GTK_WIDGET(tree_view), command, type);
next_command:   
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}*/

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

void on_any_widget_cursor_changed_event(GtkWidget *widget, AttributeSet *Attr)
{
#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	widget_signal_executor(widget, Attr, "cursor-changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/* Redundant
gboolean tree_cursor_changed(GtkTreeView *tree_view, AttributeSet *Attr)
{
	GList *element;
	gchar *command;
	gchar *signal;
	gchar *type;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command != NULL){
		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");
		if (signal == NULL || g_ascii_strcasecmp(signal, "cursor-changed") != 0)
			goto next_command;
		
		execute_action(GTK_WIDGET(tree_view), command, type);
next_command:   
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return TRUE;
}*/

/***********************************************************************
 *                                                                     *
 ***********************************************************************/
/* Events occur in this sequence when a file is recreated using rox:
 * 
 * G_FILE_MONITOR_EVENT_DELETED (2)
 * G_FILE_MONITOR_EVENT_CREATED (3)
 * G_FILE_MONITOR_EVENT_CHANGED (0)
 * G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT (1)
 * G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED (4)
 * G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT (1)
 * 
 * And from rxvt:
 * 
 * G_FILE_MONITOR_EVENT_CHANGED (0)
 * G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT (1)
 * 
 * Thanks and credit go to technosaurus for the inotify code.
 */

#if HAVE_SYS_INOTIFY_H
void on_any_widget_file_changed_event(gpointer data, gint source,
	GdkInputCondition condition)
#else
void on_any_widget_file_changed_event(GFileMonitor *monitor, GFile *file,
	GFile *other_file, GFileMonitorEvent event_type, variable *var)
#endif
{
#if HAVE_SYS_INOTIFY_H
	gchar             buffer[sizeof(struct inotify_event)];
	variable         *var = (variable*)data;
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if HAVE_SYS_INOTIFY_H
	/* Just clearing, don't care the type */
	read(source, buffer, sizeof(buffer));

#else
#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): event_type=%i filename=%s\n", __func__,
		event_type, g_file_get_path(file));
#endif

	if (event_type == G_FILE_MONITOR_EVENT_CHANGED)
#endif
	widget_signal_executor(var->Widget, var->Attributes, "file-changed");

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

#if HAVE_SYS_INOTIFY_H
void on_any_widget_auto_refresh_event(gpointer data, gint source,
	GdkInputCondition condition)
#else
void on_any_widget_auto_refresh_event(GFileMonitor *monitor, GFile *file,
	GFile *other_file, GFileMonitorEvent event_type, variable *var)
#endif
{
#if HAVE_SYS_INOTIFY_H
	gchar             buffer[sizeof(struct inotify_event)];
	variable         *var = (variable*)data;
#endif

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#if HAVE_SYS_INOTIFY_H
	/* Just clearing, don't care the type */
	read(source, buffer, sizeof(buffer));

#else
	if (event_type == G_FILE_MONITOR_EVENT_CHANGED)
#endif
	switch (var->Type) {
		case WIDGET_TOGGLEBUTTON:
		case WIDGET_BUTTON:
			widget_button_refresh(var);
			break;
		case WIDGET_CHECKBOX:
			widget_checkbox_refresh(var);
			break;
		case WIDGET_COLORBUTTON:
			widget_colorbutton_refresh(var);
			break;
		case WIDGET_COMBOBOXENTRY:
		case WIDGET_COMBOBOXTEXT:
			widget_comboboxtext_refresh(var);
			break;
		case WIDGET_EDIT:
			widget_edit_refresh(var);
			break;
		case WIDGET_ENTRY:
			widget_entry_refresh(var);
			break;
		case WIDGET_EXPANDER:
			widget_expander_refresh(var);
			break;
		case WIDGET_FONTBUTTON:
			widget_fontbutton_refresh(var);
			break;
		case WIDGET_FRAME:
			widget_frame_refresh(var);
			break;
		case WIDGET_HSCALE:
		case WIDGET_VSCALE:
			widget_hscale_refresh(var);
			break;
		case WIDGET_LIST:
			widget_list_refresh(var);
			break;
		case WIDGET_MENUITEM:
		case WIDGET_MENU:
			widget_menuitem_refresh(var);
			break;
		case WIDGET_NOTEBOOK:
			widget_notebook_refresh(var);
			break;
		case WIDGET_PIXMAP:
			widget_pixmap_refresh(var);
			break;
		case WIDGET_RADIOBUTTON:
			widget_radiobutton_refresh(var);
			break;
		case WIDGET_SPINBUTTON:
			widget_spinbutton_refresh(var);
			break;
		case WIDGET_STATUSBAR:
			widget_statusbar_refresh(var);
			break;
		case WIDGET_TABLE:
			widget_table_refresh(var);
			break;
		case WIDGET_TERMINAL:
			widget_terminal_refresh(var);
			break;
		case WIDGET_TEXT:
			widget_text_refresh(var);
			break;
		case WIDGET_TIMER:
			widget_timer_refresh(var);
			break;
#if GTK_CHECK_VERSION(2,4,0)
		case WIDGET_TREE:
			widget_tree_refresh(var);
			break;
#endif
		case WIDGET_WINDOW:
			widget_window_refresh(var);
			break;
		default:
			fprintf(stderr, "%s(): Unhandled widget type.\n", __func__);
			break;
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 *                                                                     *
 ***********************************************************************/

gboolean window_delete_event_handler(GtkWidget *widget, GtkWidget *event,
	gpointer data)
{
	variable         *var;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	//Redundant: variables_drop_by_parent(NULL, widget);
	var = find_variable_by_widget(widget);
	variables_drop_by_window_id(NULL, var->window_id);

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): variables_count_widgets()=%i\n", __func__,
		variables_count_widgets());
#endif

	if (variables_count_widgets() == 0) {
		printf("EXIT=\"abort\"\n");

#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): Calling exit(EXIT_SUCCESS)\n", __func__);
#endif

		exit(EXIT_SUCCESS);
	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return FALSE;
}

/***********************************************************************
 * Widget Signal Executor                                              *
 ***********************************************************************/
/* Thunor: With the work I've been doing I've called this function from
 * signal callbacks and let this iterate through the actions, manage the
 * default widget signal and the "if true/false" if applicable. I think
 * that originally each individual callback dealt with this but as the
 * number of widgets increases it makes sense to do everything here */

void widget_signal_executor(GtkWidget *widget, AttributeSet *Attr,
	const gchar *signal_name)
{
	GList            *element;
	gchar            *command, *type, *signal;
	gint              execute, is_active;
	variable         *var = find_variable_by_widget(widget);

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

#ifdef DEBUG_CONTENT
	fprintf(stderr, "%s(): Executing signal '%s' on widget %p\n",
		__func__, signal_name, widget);
#endif

	command = attributeset_get_first(&element, Attr, ATTR_ACTION);
	while (command) {
		execute = FALSE;
		is_active = -1;

		type = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "type");
		signal = attributeset_get_this_tagattr(&element, Attr, ATTR_ACTION, "signal");

		if (signal && g_ascii_strcasecmp(signal, signal_name) == 0) {
			/***********************************************************
			 * This manages <action signal="type">                     *
			 * i.e the specified signal                                *
			 ***********************************************************/

#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): command=%s type=%s signal=%s signal_name=%s\n",
				__func__, command, type, signal, signal_name);
#endif

			/* There's a class hierarchy to be aware of here */
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkToggleButton */
			if (GTK_IS_TOGGLE_BUTTON(widget)) {
				/* togglebuttons support conditional function execution on their active state */
				is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
/* GtkWidget--->GtkContainer--->GtkBin--->GtkExpander */
			} else if (GTK_IS_EXPANDER(widget)) {
				/* expanders support conditional function execution on their expanded state */
				is_active = gtk_expander_get_expanded(GTK_EXPANDER(widget));
/* GtkWidget--->GtkContainer--->GtkBin--->GtkItem--->GtkMenuItem--->GtkCheckMenuItem */
			} else if (GTK_IS_CHECK_MENU_ITEM(widget)) {
				/* checkbox menuitems support conditional function execution on their active state */
				is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
			}

			execute = widget_signal_executor_eval_prefix(&command, is_active);

#if 0	/* Redundant: Was also restricting conditional execution to certain
		 * signals which surely isn't correct: it should be that if it is a
		 * particular class of widget then it can check against its state.
		 * Maybe in the future I can even expand upon that state checking */
		 
			/* Some widgets support conditional function execution on certain signals */
			if (strncasecmp(command, "if true ", 8) == 0) {
				if (strcasecmp(signal_name, "activate") == 0) {
					/* There's a class hierarchy to be aware of here */
					if (GTK_IS_EXPANDER(widget)) {
						is_active = gtk_expander_get_expanded(GTK_EXPANDER(widget));
						command += 8;
						if (is_active) execute = TRUE;
					}
				} else if (strcasecmp(signal_name, "toggled") == 0) {
					/* There's a class hierarchy to be aware of here */
					if (GTK_IS_CHECK_MENU_ITEM(widget)) {
						is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
						command += 8;
						if (is_active) execute = TRUE;
					} else if (GTK_IS_TOGGLE_BUTTON(widget)) {
						is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
						command += 8;
						if (is_active) execute = TRUE;
					}
				}
			} else if (strncasecmp(command, "if false ", 9) == 0) {
				if (strcasecmp(signal_name, "activate") == 0) {
					/* There's a class hierarchy to be aware of here */
					if (GTK_IS_EXPANDER(widget)) {
						is_active = gtk_expander_get_expanded(GTK_EXPANDER(widget));
						command += 9;
						if (!is_active) execute = TRUE;
					}
				} else if (strcasecmp(signal_name, "toggled") == 0) {
					/* There's a class hierarchy to be aware of here */
					if (GTK_IS_CHECK_MENU_ITEM(widget)) {
						is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
						command += 9;
						if (!is_active) execute = TRUE;
					} else if (GTK_IS_TOGGLE_BUTTON(widget)) {
						is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
						command += 9;
						if (!is_active) execute = TRUE;
					}
				}
			} else {
				execute = TRUE;
			}
#endif	/* Redundant ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

		} else if (signal == NULL) {
			/***********************************************************
			 * This manages <action> and <action type="function">      *
			 * i.e. the default widget signal                          *
			 ***********************************************************/

#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): command=%s type=%s signal=%s signal_name=%s\n",
				__func__, command, type, signal, signal_name);
#endif

			/* There's a class hierarchy to be aware of here */
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkToggleButton */
			if (GTK_IS_TOGGLE_BUTTON(widget)) {
				if (strcasecmp(signal_name, "toggled") == 0) {
					/* togglebuttons support conditional function execution on their active state */
					is_active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkColorButton */
			} else if (GTK_IS_COLOR_BUTTON(widget)) {
				if (strcasecmp(signal_name, "color-set") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton--->GtkFontButton */
			} else if (GTK_IS_FONT_BUTTON(widget)) {
				if (strcasecmp(signal_name, "font-set") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBin--->GtkButton */
			} else if (GTK_IS_BUTTON(widget)) {
				if (strcasecmp(signal_name, "clicked") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBin--->GtkExpander */
			} else if (GTK_IS_EXPANDER(widget)) {
				if (strcasecmp(signal_name, "activate") == 0) {
					/* expanders support conditional function execution on their expanded state */
					is_active = gtk_expander_get_expanded(GTK_EXPANDER(widget));
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBin--->GtkItem--->GtkMenuItem--->GtkCheckMenuItem */
			} else if (GTK_IS_CHECK_MENU_ITEM(widget)) {
				if (strcasecmp(signal_name, "toggled") == 0) {
					/* checkbox menuitems support conditional function execution on their active state */
					is_active = gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget));
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBin--->GtkItem--->GtkMenuItem */
			} else if (GTK_IS_MENU_ITEM(widget)) {
				if (strcasecmp(signal_name, "activate") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkBox--->GtkHBox--->GtkCombo */
			} else if (GTK_IS_COMBO_BOX(widget)) {
				if (strcasecmp(signal_name, "changed") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkCList */
			} else if (GTK_IS_CLIST(widget)) {
				if (strcasecmp(signal_name, "select-row") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkList */
			} else if (GTK_IS_LIST(widget)) {
				if (strcasecmp(signal_name, "selection-changed") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkContainer--->GtkTreeView */
			} else if (GTK_IS_TREE_VIEW(widget)) {
				if (strcasecmp(signal_name, "row-activated") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkEntry-->GtkSpinButton */
			} else if (GTK_IS_SPIN_BUTTON(widget)) {
				if (strcasecmp(signal_name, "value-changed") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkEntry */
			} else if (GTK_IS_ENTRY(widget)) {
				if (strcasecmp(signal_name, "changed") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkMisc--->GtkLabel */
			} else if (GTK_IS_LABEL(widget)) {
				/* A GtkLabel that ticks is a timer */
				if (strcasecmp(signal_name, "tick") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkProgress--->GtkProgressBar */
			} else if (GTK_IS_PROGRESS_BAR(widget)) {
				if (strcasecmp(signal_name, "time-out") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
/* GtkWidget--->GtkRange--->GtkScale */
			} else if (GTK_IS_SCALE(widget)) {
				if (strcasecmp(signal_name, "value-changed") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
#if HAVE_VTE
/* GtkWidget--->VteTerminal */
			} else if (VTE_IS_TERMINAL(widget)) {
				if (strcasecmp(signal_name, "child-exited") == 0) {
					execute = widget_signal_executor_eval_prefix(&command, is_active);
				}
#endif
			}
		}

		if (execute) execute_action(widget, command, type);
		command = attributeset_get_next(&element, Attr, ATTR_ACTION);

	}

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif
}

/***********************************************************************
 * Widget Signal Executor - Evaluate Prefix                            *
 ***********************************************************************/
/* On entry: command is a pointer to a pointer to the command string
 *           is_active = 1, 0 or -1 if not applicable
 *  On exit: returns true if action valid or false */

gboolean widget_signal_executor_eval_prefix(gchar **command, gint is_active)
{
	FILE             *infile;
	gchar             filename[256];
	gchar             line[64] = "";
	gint              count;
	gint              index;
	gint              not;
	gint              retval = FALSE;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "\n%s(): Entering.\n", __func__);
	fprintf(stderr, "%s():    *command=%s\n", __func__, *command);
#endif

	/*****************************************************
	 * Active state true conditional function execution  *
	 *****************************************************/
	if ((strncasecmp(*command, "if true ", 8) == 0) && (is_active > -1)) {

#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): if true detected\n", __func__);
#endif
		*command += 8;
		if (is_active) retval = TRUE;

	/*****************************************************
	 * Active state false conditional function execution *
	 *****************************************************/
	} else if ((strncasecmp(*command, "if false ", 9) == 0) && (is_active > -1)) {

#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s(): if false detected\n", __func__);
#endif
		*command += 9;
		if (!is_active) retval = TRUE;

	/*****************************************************
	 * Input file conditional function execution         *
	 *****************************************************/
	} else if ((strncasecmp(*command, "if file(", 8) == 0) ||
		(strncasecmp(*command, "if file (", 9) == 0) ||
		(strncasecmp(*command, "if !file(", 9) == 0) ||
		(strncasecmp(*command, "if ! file(", 10) == 0) ||
		(strncasecmp(*command, "if !file (", 10) == 0) ||
		(strncasecmp(*command, "if ! file (", 11) == 0)) {

		/* Are we looking for true or false? */
		if (strncasecmp(*command, "if !", 4) == 0) {
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): if ! file() detected\n", __func__);
#endif
			not = TRUE;
		} else {
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): if file() detected\n", __func__);
#endif
			not = FALSE;
		}

		/* Locate filename start and update pointer */
		*command = strchr(*command, '(') + 1;

		/* Get filename, locate end [properly] and update pointer */
		strcpy(filename, *command);
		count = 1; index = 0;
		while (**command) {
			if (**command == '(') count++;
			if (**command == ')') count--;
			(*command)++;
			if (!count) break;
			index++;
		}
		filename[index] = 0;

		/* There may have been spaces inside the brackets */
		g_strstrip(filename);

		if (infile = fopen(filename, "r")) {
			/* Just one line */
			if (fgets(line, 64, infile)) {
				/* Enforce end of string in case of max chars read */
				line[64 - 1] = 0;
				/* Remove the trailing [CR]LFs */
				for (count = strlen(line) - 1; count >= 0; count--)
					if (line[count] == 13 || line[count] == 10) line[count] = 0;
			}

			if (not) {
				if ((strcasecmp(line, "false") == 0) ||
					(strcasecmp(line, "no") == 0) ||
					(strcasecmp(line, "0") == 0)) {
					retval = TRUE;
				}
			} else {
				if ((strcasecmp(line, "true") == 0) ||
					(strcasecmp(line, "yes") == 0) ||
					(atoi(line))) {
					retval = TRUE;
				}
			}

			/* Close the file */
			fclose(infile);
		} else {
			fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
				filename);
		}

#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s():        filename=%s\n", __func__, filename);
		fprintf(stderr, "%s():        line=%s\n", __func__, line);
		fprintf(stderr, "%s():        *command=%s\n", __func__, *command);
		fprintf(stderr, "%s():        retval=%i\n", __func__, retval);
#endif

	/*****************************************************
	 * Shell command conditional function execution      *
	 *****************************************************/
	} else if ((strncasecmp(*command, "if command(", 11) == 0) ||
		(strncasecmp(*command, "if command (", 12) == 0) ||
		(strncasecmp(*command, "if !command(", 12) == 0) ||
		(strncasecmp(*command, "if ! command(", 13) == 0) ||
		(strncasecmp(*command, "if !command (", 13) == 0) ||
		(strncasecmp(*command, "if ! command (", 14) == 0)) {

		/* Are we looking for true or false? */
		if (strncasecmp(*command, "if !", 4) == 0) {
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): if ! command() detected\n", __func__);
#endif
			not = TRUE;
		} else {
#ifdef DEBUG_CONTENT
			fprintf(stderr, "%s(): if command() detected\n", __func__);
#endif
			not = FALSE;
		}

		/* Locate filename start and update pointer */
		*command = strchr(*command, '(') + 1;

		/* Get filename, locate end [properly] and update pointer */
		strcpy(filename, *command);
		count = 1; index = 0;
		while (**command) {
			if (**command == '(') count++;
			if (**command == ')') count--;
			(*command)++;
			if (!count) break;
			index++;
		}
		filename[index] = 0;

		/* There may have been spaces inside the brackets */
		g_strstrip(filename);

		/* Do as action_shellcommand() does */
		variables_export_all();

		/* Opening pipe for reading... */
		if (infile = widget_opencommand(filename)) {
			/* Just one line */
			if (fgets(line, 64, infile)) {
				/* Enforce end of string in case of max chars read */
				line[64 - 1] = 0;
				/* Remove the trailing [CR]LFs */
				for (count = strlen(line) - 1; count >= 0; count--)
					if (line[count] == 13 || line[count] == 10) line[count] = 0;
			}

			if (not) {
				if ((strcasecmp(line, "false") == 0) ||
					(strcasecmp(line, "no") == 0) ||
					(strcasecmp(line, "0") == 0)) {
					retval = TRUE;
				}
			} else {
				if ((strcasecmp(line, "true") == 0) ||
					(strcasecmp(line, "yes") == 0) ||
					(atoi(line))) {
					retval = TRUE;
				}
			}

			/* Close the file */
			pclose(infile);
		} else {
			fprintf(stderr, "%s(): Couldn't open '%s' for reading.\n", __func__,
				filename);
		}

#ifdef DEBUG_CONTENT
		fprintf(stderr, "%s():        filename=%s\n", __func__, filename);
		fprintf(stderr, "%s():        line=%s\n", __func__, line);
		fprintf(stderr, "%s():        *command=%s\n", __func__, *command);
		fprintf(stderr, "%s():        retval=%i\n", __func__, retval);
#endif

	} else {
		retval = TRUE;
	}

	/* Preceding the remainder of the command could be whitespace so
	 * skip over it and update the pointer */
	while (**command && **command == ' ') (*command)++;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s():    *command=%s\n", __func__, *command);
	fprintf(stderr, "%s():    retval=%i\n", __func__, retval);
	fprintf(stderr, "%s(): Exiting.\n", __func__);
#endif

	return retval;
}

/***********************************************************************
 * Widget File Monitor Try Create                                      *
 ***********************************************************************/
/* If the tag attribute file-monitor is true then attempt to create a
 * file monitor and emit a signal on change.
 * 
 * If the tag attribute auto-refresh is true then attempt to create a
 * file monitor and connect directly to the widget's refresh function.
 * 
 * The monitor object is attached to the widget as a piece of data
 * with a unique sequential name starting at "_monitor0" which will be
 * used later to cancel the monitor when/if the widget is dropped.
 * 
 * Thanks and credit go to technosaurus for the inotify code.
 */

#if HAVE_SYS_INOTIFY_H
void widget_file_monitor_try_create(variable *var, gchar *filename)
{
	gchar             fdname[16];
	gchar             wdname[16];
	gchar            *value;
	gint              count;
	gint              fd, wd;
	gint              index = 0;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Is this file going to be monitored? */
	if (var->widget_tag_attr) {

		for (count = 0; count < 2; count++) {

			/* Get file-monitor (custom) or auto-refresh (custom) */
			if (((!count && (value = get_tag_attribute(var->widget_tag_attr,
				"file-monitor"))) ||
				(count && (value = get_tag_attribute(var->widget_tag_attr,
				"auto-refresh")))) && ((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1))) {

				if ((fd = inotify_init()) != -1) {

					if ((wd = inotify_add_watch(fd, (gchar*)filename,
						IN_MODIFY)) != -1) {
#ifdef DEBUG_CONTENT
						fprintf(stderr, "%s(): fd=%i wd=%i\n", __func__,
							fd, wd);
#endif
						/* Generate unique name */
						while (TRUE) {
							sprintf(fdname, "_inotifyfd%i", index);
							sprintf(wdname, "_inotifywd%i", index);
							if (!(g_object_get_data(G_OBJECT(var->Widget),
								fdname))) break;
							index++;
						}
#ifdef DEBUG_CONTENT
						fprintf(stderr, "%s(): fdname=%s wdname=%s\n",
							__func__, fdname, wdname);
#endif
						/* Store fd as a piece of widget data */
						g_object_set_data(G_OBJECT(var->Widget), fdname,
							(gpointer)fd);

						/* Store wd as a piece of widget data */
						g_object_set_data(G_OBJECT(var->Widget), wdname,
							(gpointer)wd);

						if (!count) {
							/* Connect to the "changed" signal which will reach
							 * the application as the "file-changed" signal */
							gdk_input_add(fd, GDK_INPUT_READ,
								on_any_widget_file_changed_event, (gpointer)var); 
						} else {
							/* Connect to the "changed" signal which will call
							 * the widget's refresh function directly without
							 * being routed through gtkdialog's signal handling
							 * system and without emitting a signal (it's faster) */
							gdk_input_add(fd, GDK_INPUT_READ,
								on_any_widget_auto_refresh_event, (gpointer)var); 
						}

					} else {
						if (fd != -1) close(fd);
					}
				}
				if (fd == -1 || wd == -1)
					fprintf(stderr, "%s(): Couldn't create file monitor for '%s'.\n",
						__func__, filename);
			}
		}
	}
}

#else
void widget_file_monitor_try_create(variable *var, gchar *filename)
{
	GError           *error;
	GFile            *file;
	GFileMonitor     *monitor;
	gchar             name[16];
	gchar            *value;
	gint              count;
	gint              index = 0;
	gint              fd, wd;

#ifdef DEBUG_TRANSITS
	fprintf(stderr, "%s(): Entering.\n", __func__);
#endif

	/* Is this file going to be monitored? */
	if (var->widget_tag_attr) {

		for (count = 0; count < 2; count++) {

			/* Get file-monitor (custom) or auto-refresh (custom) */
			if (((!count && (value = get_tag_attribute(var->widget_tag_attr,
				"file-monitor"))) ||
				(count && (value = get_tag_attribute(var->widget_tag_attr,
				"auto-refresh")))) && ((strcasecmp(value, "true") == 0) ||
				(strcasecmp(value, "yes") == 0) || (atoi(value) == 1))) {

				/* GIO Reference states this function will never fail */
				if ((file = g_file_new_for_path(find_pixmap(filename)))) {

					/* I can't make this return NULL although if the
					 * file doesn't exist then it just doesn't work */
					error = NULL;
					monitor = g_file_monitor_file(file, G_FILE_MONITOR_NONE,
						FALSE, &error);

#ifdef DEBUG_CONTENT
					fprintf(stderr, "%s(): file=%p monitor=%p\n", __func__,
						file, monitor);
#endif

					if (monitor) {

						/* Get rate-limit (custom) */
						if ((value = get_tag_attribute(var->widget_tag_attr,
							"rate-limit"))) {
							/* I tested this and couldn't detect a change */
							g_file_monitor_set_rate_limit(monitor, atoi(value));
						}

						/* Generate unique name */
						while (TRUE) {
							sprintf(name, "_monitor%i", index++);
							if (!(g_object_get_data(G_OBJECT(var->Widget), name)))
								break;
						}

#ifdef DEBUG_CONTENT
						fprintf(stderr, "%s(): name=%s\n", __func__, name);
#endif

						/* Store monitor as a piece of widget data */
						g_object_set_data(G_OBJECT(var->Widget), name,
							(gpointer)monitor);

						if (!count) {
							/* Connect to the "changed" signal which will reach
							 * the application as the "file-changed" signal */
							g_signal_connect(monitor, "changed",
								G_CALLBACK(on_any_widget_file_changed_event),
								(gpointer)var);
						} else {
							/* Connect to the "changed" signal which will call
							 * the widget's refresh function directly without
							 * being routed through gtkdialog's signal handling
							 * system and without emitting a signal (it's faster) */
							g_signal_connect(monitor, "changed",
								G_CALLBACK(on_any_widget_auto_refresh_event),
								(gpointer)var);
						}

					} else {
						if (file) g_object_unref(file);
					}
				}
				if (!file || !monitor)
					fprintf(stderr, "%s(): Couldn't create file monitor for '%s'.\n",
						__func__, filename);
			}
		}
	}
}
#endif

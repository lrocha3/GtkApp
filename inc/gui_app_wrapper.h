#ifndef GUI_APP_WRAPPER_H
#define GUI_APP_WRAPPER_H

#include "definitions.h"

/* My SQL includes */
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/* GTK includes */
#include <gtk/gtk.h>

void on_button_clicked(GtkWidget *widget, gpointer data);
bool MySQLDriver_Func();

#endif

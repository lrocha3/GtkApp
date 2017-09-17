#include "gui_app_wrapper.h"
#include "definitions.h"

/* My SQL includes */
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/* GTK includes */
#include <gtk/gtk.h>
#include <gtk/gtkswitch.h>

void on_button_clicked(GtkWidget *widget, gpointer data) {
	GtkSwitch* slider = (GtkSwitch*) data;

	bool return_data = MySQLDriver_Func();

	if (slider && return_data == true) {
		gtk_switch_set_state(slider, true);
	}
}

bool MySQLDriver_Func() {
	bool return_data = false;
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://lrocha3.no-ip.org:3306", "dev", "development");
		/* Connect to the MySQL test database */

		if (con) {
			g_print("Connected\n");
			return_data = true;
		}
	} catch (sql::SQLException &e) {
		char buffer [100];
		sprintf(buffer, "ERROR: %s (MySQL error code: %d, SQLState: %s)", e.what(), e.getErrorCode(), e.getSQLState().c_str());
		g_print("%s\n", buffer);
	}

	return return_data;
}


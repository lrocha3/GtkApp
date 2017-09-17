#include <gtk/gtk.h>

#include "gui_app_wrapper.h"

using namespace std;

int main(int argc, char** argv) {
	gtk_init(&argc, &argv);

	/* Builder object to load the glad file */
	GtkBuilder* builder = gtk_builder_new();

	/* Load the XML/glade file. */
	gtk_builder_add_from_file(builder, "assets/myGuiFile.glade", nullptr);

	/* Get the main_window object from the glade file */
	GObject* window = gtk_builder_get_object(builder, "window_main");

	/* Center in the window in the middle of screen */
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	/* Set the window size */
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

	/* Set the window title */
	gtk_window_set_title(GTK_WINDOW(window), "Gui_app");

	/* Display the window */
	gtk_widget_show(GTK_WIDGET(window));

	/* Get the button and slider object from the glade file */
	GObject* button = gtk_builder_get_object(builder, "button");
	GObject* slider = gtk_builder_get_object(builder, "slider");

	/* Connect the button to the on_button_clicked callback and send the slider object as a parameter */
	g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), slider);

	/* Connect the window destroy event to the gtk_main_quit to exit the application */
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), nullptr);

	/* Main GTK loop */
	gtk_main();

	return 0;
}

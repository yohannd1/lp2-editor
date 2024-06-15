#include <gtk/gtk.h>

static void cb_activate(GtkApplication *app, gpointer data);
static void cb_print_hello(GtkWidget *wid, gpointer data);
static void cb_quit(GtkWindow *win);

int main(int argc, char **argv) {
#ifdef GTK_SRCDIR
	g_chdir (GTK_SRCDIR);
#endif

	GtkApplication *app = gtk_application_new("lp2.editor_texto", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app, "activate", G_CALLBACK(cb_activate), NULL);

	int status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

static void cb_activate(GtkApplication *app, gpointer user_data) {
	// criar a janela
	GtkWidget *window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Editor");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

	GtkWidget *grid = gtk_grid_new();
	gtk_window_set_child(GTK_WINDOW(window), grid);

	// hello world
	GtkWidget *btn_hello = gtk_button_new_with_label("Say hello");
	g_signal_connect(btn_hello, "clicked", G_CALLBACK(cb_print_hello), NULL);
	gtk_grid_attach(GTK_GRID(grid), btn_hello, 0, 0, 1, 1);

	GtkWidget *btn_quit = gtk_button_new_with_label("Quit");
	g_signal_connect(btn_quit, "clicked", G_CALLBACK(cb_quit), NULL);
	gtk_grid_attach(GTK_GRID(grid), btn_quit, 0, 1, 1, 1);

	GtkWidget *text_view = gtk_text_view_new();
	GtkTextBuffer *text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
	gtk_text_buffer_set_text(text_buffer, "Hello world", -1);
	gtk_grid_attach(GTK_GRID(grid), text_view, 0, 1, 2, 1);

	// mostrar a janela
	gtk_window_present(GTK_WINDOW(window));
}

static void cb_print_hello(GtkWidget *wid, gpointer data) {
	g_print("Hello World\n");
}

static void cb_quit(GtkWindow *win) {
	gtk_window_close(win);
}

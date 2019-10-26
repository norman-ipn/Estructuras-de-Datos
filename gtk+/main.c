#include<gtk/gtk.h>
#include<string.h>

/* Datos globales accessibles desde cualquier punto
de la aplicación */
GtkEntry *entrada_nombre = NULL;
GtkLabel *etiqueta_saludo = NULL;
char saludo[256];


/* función que será llamada cuando se haga clic en el botón
NOTA: es necesario registrar la función como un 'callback_symbol'.
Esto se hace en dos puntos:
1. En el main. llamando a gtk_builder_add_callback_symbol.
2. En el archivo .ui que se crea con glade. en la señal 'clicked' del botón.
*/
static void
saludar (GtkWidget * boton, gpointer data)
{
  const gchar *nombre = NULL;
  int tam_nombre = 0;

  nombre = gtk_entry_get_text (entrada_nombre);
  tam_nombre = strlen (nombre);

  if (0 < tam_nombre && tam_nombre < 70)
    {
      sprintf (saludo, "!Hola %s!", nombre);
    }
  else
    {
      sprintf (saludo, "!Hola Mundo!");
    }

  gtk_label_set_text (etiqueta_saludo, saludo);
}



int
main (int argc, char **argv)
{
  GtkBuilder *constructor = NULL;
  GtkWidget *ventana = NULL;

  gtk_init (&argc, &argv);

  constructor = gtk_builder_new_from_file ("ejemplo.ui");
  gtk_builder_add_callback_symbol (constructor, "saludar",
				   G_CALLBACK (saludar));
  gtk_builder_connect_signals (constructor, NULL);

  ventana =
    GTK_WIDGET (gtk_builder_get_object (constructor, "ventana_principal"));

  entrada_nombre =
    GTK_ENTRY (gtk_builder_get_object (constructor, "entrada_nombre"));

  etiqueta_saludo =
    GTK_LABEL (gtk_builder_get_object (constructor, "etiqueta_saludo"));

  gtk_widget_show (ventana);

  gtk_main ();

  return 0;
}

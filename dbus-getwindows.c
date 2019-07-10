/*
 * This uses the recommended GLib API for D-Bus: GDBus,
 * which has been distributed with GLib since version 2.26.
 *
 * For details of how to use GDBus, see:
 * https://developer.gnome.org/gio/stable/gdbus-convenience.html
 *
 * dbus-glib also exists but is deprecated.
 */
#include <stdbool.h>
#include <stdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>


void test_getwindows(GDBusProxy *proxy)
{
   GVariant *result;
   GError *error = NULL;
   GVariant *win_params;
   GVariantIter *iter;
   gchar *wm_class;
   gchar *title;
   gint64 win_id;

   g_printf("Calling GetWindows()...\n");
   result = g_dbus_proxy_call_sync(proxy,
               "GetWindows",
               NULL,
               G_DBUS_CALL_FLAGS_NONE,
               -1,
               NULL,
               &error);
   g_assert_no_error(error);

   g_variant_get (result, "(a{ta{sv}})", &iter);
   while (g_variant_iter_loop (iter, "{t@a{sv}}",&win_id, &win_params)) {
      g_variant_lookup (win_params, "wm-class", "s", &wm_class);
      g_variant_lookup (win_params, "title", "s", &title);
      g_print ("%ld=%s--%s\n", win_id, wm_class, title);
   }
   g_variant_iter_free (iter);

   g_printf("\nThe complete answer:\n'%s'\n", g_variant_print_string (result, NULL, TRUE)->str);

   g_variant_unref(result);
}

int main(void)
{
   GDBusProxy *proxy;
   GDBusConnection *conn;
   GError *error = NULL;

   conn = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &error);
   g_assert_no_error(error);

   proxy = g_dbus_proxy_new_sync(conn,
                  G_DBUS_PROXY_FLAGS_NONE,
                  NULL,
                  "org.gnome.Shell", 
                  "/org/gnome/Shell/Introspect",
                  "org.gnome.Shell.Introspect",
                  NULL,
                  &error);
   g_assert_no_error(error);

   test_getwindows(proxy);
   g_object_unref(proxy);
   g_object_unref(conn);
   return 0;
}

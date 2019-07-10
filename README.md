# dbus org.gnome.Shell GetWindows call from C

This project is a quick try to retrieve info about available windows:

- [org.gnome.Shell GetWindows API](https://gitlab.gnome.org/ofourdan/gnome-shell/commit/3b08987512393937a1b6d5c3ff0fc459978e7413)
- [related issue](https://github.com/flatpak/xdg-desktop-portal-gtk/issues/204)

## Build

```
make
```

## Result

```
$ ./dbus-getwindows 
Calling GetWindows()...
1036210437=Google-chrome--albfan/dbus-getwindows - Google Chrome
1036210438=Google-chrome--Blue Jeans Network | Video Collaboration in the Cloud - Google Chrome
1036210479=terminator--alberto@archlinux-alberto: ~/projects/system/dbus-getwindows
1036210511=polari--aps-support
1036211365=gnome-builder--Builder ? diferencia
1036211501=Google-chrome--Hangouts de Google - albertofanjul@gmail.com
1036211688=devhelp--GVariant: GLib Reference Manual
1036211707=d-feet--d-feet
1036211717=d-feet--Ejecutar el m?todo de D-Bus
1036211797=xdg-desktop-portal-gtk--Captura de v?deo
1036211798=xdg-desktop-portal-gtk--Captura de v?deo

The complete answer:
'({uint64 1234567890: {'app-id': <'app.desktop'>, ...}},)'
```

## Credits

https://github.com/fbuihuu/samples-dbus

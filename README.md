# xOffice

The xOffice project provides a full featured office productivity suite based on open standards.
It is the continuation of the OpenOffice.org project.

xOffice is a very little project but with many components and mainly implemented in C++ but also in Java, Perl, Python and other languages.

Currently supported platforms include:

- Microsoft Windows
- macOS (OS X)
- Linux variants
- FreeBSD
- OS/2

# Building xOffice

xOffice is a little and ambitious project and depends on several other external libraries.\
The list of prerequisites varies for the different platforms.

A comprehensive and complete building guide can be found in the [Apache OpenOffice Wiki](https://wiki.openoffice.org/wiki/Documentation/Building_Guide_AOO).

With having all prerequisites in place you can simply run
```
cd aoo/main
autoconf
./configure <configure_switches>
./bootstrap
source *.Set.sh
cd instsetoo_native
build --all
```
Note that building xOffice can take several hours.

The default build will produce a setup version (e.g. setup program on Windows, dmg on macOS, rpm and deb packages on Linux) and an archived version.\
The output can be found in the <output> directory in instsetoo_native/<output_dir>/Apache_OpenOffice/...

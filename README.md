# cpp_rest_handler# cpp_rest_handler

## **Index**

- [Building Curl Library](#building-curl-library)
- [Building Project](#building-project)

## **Building Curl Library**
###### [Index](#index)

`git clone https://github.com/curl/curl.git` // Download the latest git repo

`sudo apt install libssl-dev libc-ares2 libc-ares-dev libssh-dev libssh2-1-dev` // If on an Ubuntu system, this needs to be installed for openssl to install properly in curl. openssl-devel is used on RHEL

`sudo ./configure --prefix=/mnt/c/Users/chwc8/GitHub/curl/curl --disable-shared --with-ssl --with-libssl-prefix=/usr/include/openssl` // built using OpenSSL 3.0.2 15 Mar 2022 (Library: OpenSSL 3.0.2 15 Mar 2022). The **--disable-shared** is required to get a static library

`sudo ./configure --disable-shared --enable-static --with-openssl --enable-debug --enable-ares --enable-get-easy-options --with-libssh2 --libdir=/usr/lib/curl/lib --includedir=/usr/lib/curl/include` // Not sure all my --with options trying to use are correct yet. Like do I want libssh or libssh2?

`sudo ./configure --disable-shared --enable-static --with-openssl --enable-debug --enable-ares --enable-get-easy-options --libdir=/usr/lib/curl/lib --includedir=/usr/lib/curl/include` // Not sure all my --with options trying to use are correct yet.

`sudo ./configure --disable-shared --enable-static --prefix=/tmp/curl --disable-ldap --disable-sspi --without-librtmp --disable-ftp --disable-file --disable-dict --disable-telnet --disable-tftp --disable-rtsp --disable-pop3 --disable-imap --disable-smtp --disable-gopher --disable-smb --without-libidn --enable-ares` // This was an example. Don't need

configure: Configured to build curl/libcurl:

  Host setup:       x86_64-pc-linux-gnu
  Install prefix:   /usr/local
  Compiler:         gcc
   CFLAGS:          -Werror-implicit-function-declaration -g -O0 -std=gnu89 -pedantic -Wall -W -Wpointer-arith -Wwrite-strings -Wunused -Wshadow -Winline -Wnested-externs -Wmissing-declarations -Wmissing-prototypes -Wno-long-long -Wbad-function-cast -Wfloat-equal -Wno-multichar -Wsign-compare -Wundef -Wno-format-nonliteral -Wendif-labels -Wstrict-prototypes -Wdeclaration-after-statement -Wold-style-definition -Wstrict-aliasing=3 -Wcast-align -Wtype-limits -Wold-style-declaration -Wmissing-parameter-type -Wempty-body -Wclobbered -Wignored-qualifiers -Wconversion -Wno-sign-conversion -Wvla -ftree-vrp -Wdouble-promotion -Wformat=2 -Warray-bounds=2 -Wshift-negative-value -Wshift-overflow=2 -Wnull-dereference -fdelete-null-pointer-checks -Wduplicated-cond -Wunused-const-variable -Wduplicated-branches -Wrestrict -Walloc-zero -Wformat-overflow=2 -Wformat-truncation=2 -Wimplicit-fallthrough=4 -Warith-conversion -Wenum-conversion -Wno-system-headers
   CPPFLAGS:
   LDFLAGS:
   LIBS:            -lcares -lssh2 -lssl -lcrypto -lz

  curl version:     8.5.0-DEV
  SSL:              enabled (OpenSSL v3+)
  SSH:              enabled (libSSH2)
  zlib:             enabled
  brotli:           no      (--with-brotli)
  zstd:             no      (--with-zstd)
  GSS-API:          no      (--with-gssapi)
  GSASL:            no      (libgsasl not found)
  TLS-SRP:          enabled
  resolver:         c-ares
  IPv6:             enabled
  Unix sockets:     enabled
  IDN:              no      (--with-{libidn2,winidn})
  Build libcurl:    Shared=no, Static=yes
  Built-in manual:  enabled
  --libcurl option: enabled (--disable-libcurl-option)
  Verbose errors:   enabled (--disable-verbose)
  Code coverage:    disabled
  SSPI:             no      (--enable-sspi)
  ca cert bundle:   /etc/ssl/certs/ca-certificates.crt
  ca cert path:     /etc/ssl/certs
  ca fallback:      no
  LDAP:             no      (--enable-ldap / --with-ldap-lib / --with-lber-lib)
  LDAPS:            no      (--enable-ldaps)
  RTSP:             enabled
  RTMP:             no      (--with-librtmp)
  PSL:              no      (libpsl not found)
  Alt-svc:          enabled (--disable-alt-svc)
  Headers API:      enabled (--disable-headers-api)
  HSTS:             enabled (--disable-hsts)
  HTTP1:            enabled (internal)
  HTTP2:            no      (--with-nghttp2, --with-hyper)
  HTTP3:            no      (--with-ngtcp2 --with-nghttp3, --with-quiche, --with-msh3)
  ECH:              no      (--enable-ech)
  WebSockets:       no      (--enable-websockets)
  Protocols:        DICT FILE FTP FTPS GOPHER GOPHERS HTTP HTTPS IMAP IMAPS MQTT POP3 POP3S RTSP SCP SFTP SMB SMBS SMTP SMTPS TELNET TFTP
  Features:         AsynchDNS HSTS HTTPS-proxy IPv6 Largefile NTLM SSL TLS-SRP UnixSockets alt-svc libz threadsafe

`sudo make` // Run after the configure successfully completes.

`sudo make install` // Run after make completes successfully

chasexd@ChaseGamingPC:/usr/lib/curl$ sudo make install
Making install in lib
make[1]: Entering directory '/usr/lib/curl/lib'
  RUN      checksrc
make[2]: Entering directory '/usr/lib/curl/lib'
 /usr/bin/mkdir -p '/usr/lib/curl/lib'
 /bin/bash ../libtool   --mode=install /usr/bin/install -c   libcurl.la '/usr/lib/curl/lib'
libtool: install: /usr/bin/install -c .libs/libcurl.lai /usr/lib/curl/lib/libcurl.la
libtool: install: /usr/bin/install -c .libs/libcurl.a /usr/lib/curl/lib/libcurl.a
libtool: install: chmod 644 /usr/lib/curl/lib/libcurl.a
libtool: install: ranlib /usr/lib/curl/lib/libcurl.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/lib/curl/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/lib/curl/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[2]: Nothing to be done for 'install-data-am'.
make[2]: Leaving directory '/usr/lib/curl/lib'
make[1]: Leaving directory '/usr/lib/curl/lib'
Making install in src
make[1]: Entering directory '/usr/lib/curl/src'
Making install in ../docs
make[2]: Entering directory '/usr/lib/curl/docs'
Making install in .
make[3]: Entering directory '/usr/lib/curl/docs'
make[4]: Entering directory '/usr/lib/curl/docs'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/local/share/man/man1'
 /usr/bin/install -c -m 644 curl-config.1 /usr/lib/curl/docs/curl.1 '/usr/local/share/man/man1'
make[4]: Leaving directory '/usr/lib/curl/docs'
make[3]: Leaving directory '/usr/lib/curl/docs'
Making install in cmdline-opts
make[3]: Entering directory '/usr/lib/curl/docs/cmdline-opts'
make[4]: Entering directory '/usr/lib/curl/docs/cmdline-opts'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/usr/lib/curl/docs/cmdline-opts'
make[3]: Leaving directory '/usr/lib/curl/docs/cmdline-opts'
make[2]: Leaving directory '/usr/lib/curl/docs'
make[2]: Entering directory '/usr/lib/curl/src'
  CCLD     curl
  RUN      checksrc
make[3]: Entering directory '/usr/lib/curl/src'
 /usr/bin/mkdir -p '/usr/local/bin'
  /bin/bash ../libtool   --mode=install /usr/bin/install -c curl '/usr/local/bin'
libtool: install: /usr/bin/install -c curl /usr/local/bin/curl
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/usr/lib/curl/src'
make[2]: Leaving directory '/usr/lib/curl/src'
make[1]: Leaving directory '/usr/lib/curl/src'
make[1]: Entering directory '/usr/lib/curl'
make[2]: Entering directory '/usr/lib/curl'
 /usr/bin/mkdir -p '/usr/local/bin'
 /usr/bin/install -c curl-config '/usr/local/bin'
 /usr/bin/mkdir -p '/usr/lib/curl/lib/pkgconfig'
 /usr/bin/install -c -m 644 libcurl.pc '/usr/lib/curl/lib/pkgconfig'
make  install-data-hook
make[3]: Entering directory '/usr/lib/curl'
(cd include && make install)
make[4]: Entering directory '/usr/lib/curl/include'
Making install in curl
make[5]: Entering directory '/usr/lib/curl/include/curl'
  RUN      checksrc
make[6]: Entering directory '/usr/lib/curl/include/curl'
make[6]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/lib/curl/include/curl'
 /usr/bin/install -c -m 644 curl.h curlver.h easy.h mprintf.h stdcheaders.h multi.h typecheck-gcc.h system.h urlapi.h options.h header.h websockets.h '/usr/lib/curl/include/curl'
/usr/bin/install: 'curl.h' and '/usr/lib/curl/include/curl/curl.h' are the same file
/usr/bin/install: 'curlver.h' and '/usr/lib/curl/include/curl/curlver.h' are the same file
/usr/bin/install: 'easy.h' and '/usr/lib/curl/include/curl/easy.h' are the same file
/usr/bin/install: 'mprintf.h' and '/usr/lib/curl/include/curl/mprintf.h' are the same file
/usr/bin/install: 'stdcheaders.h' and '/usr/lib/curl/include/curl/stdcheaders.h' are the same file
/usr/bin/install: 'multi.h' and '/usr/lib/curl/include/curl/multi.h' are the same file
/usr/bin/install: 'typecheck-gcc.h' and '/usr/lib/curl/include/curl/typecheck-gcc.h' are the same file
/usr/bin/install: 'system.h' and '/usr/lib/curl/include/curl/system.h' are the same file
/usr/bin/install: 'urlapi.h' and '/usr/lib/curl/include/curl/urlapi.h' are the same file
/usr/bin/install: 'options.h' and '/usr/lib/curl/include/curl/options.h' are the same file
/usr/bin/install: 'header.h' and '/usr/lib/curl/include/curl/header.h' are the same file
/usr/bin/install: 'websockets.h' and '/usr/lib/curl/include/curl/websockets.h' are the same file
make[6]: *** [Makefile:485: install-pkgincludeHEADERS] Error 1
make[6]: Leaving directory '/usr/lib/curl/include/curl'
make[5]: *** [Makefile:603: install-am] Error 2
make[5]: Leaving directory '/usr/lib/curl/include/curl'
make[4]: *** [Makefile:499: install-recursive] Error 1
make[4]: Leaving directory '/usr/lib/curl/include'
make[3]: *** [Makefile:1782: install-data-hook] Error 2
make[3]: Leaving directory '/usr/lib/curl'
make[2]: *** [Makefile:1610: install-data-am] Error 2
make[2]: Leaving directory '/usr/lib/curl'
make[1]: *** [Makefile:1563: install-am] Error 2
make[1]: Leaving directory '/usr/lib/curl'
make: *** [Makefile:1251: install-recursive] Error 1



`./curl-config --cflags` The make will create this curl-config, which can be used to find the dependencies required for curl to work. And list out the directories you need to include when compiling your project. [For Reference on using the curl-config tool](https://curl.se/libcurl/using/).</br>
Should return something similar to `-DCURL_STATICLIB -I/usr/lib/curl/include`

`./curl-config --static-libs` // Should return something similar `/usr/lib/curl/lib/libcurl.a -lcares -lssh2 -lssl -lcrypto -lz`

`./curl-config --feature | grep SSL` // Returns something similar if it was built using SSL support, `SSL`

`./curl-config --version` // Returns the installed libcurl version.</br>
The current version being used is `libcurl 8.5.0-DEV`

Note to self, need to understand how g++ works and how to tshoot it better.














## **Building Project**
###### [Index](#index)

When building with VSCode:

```
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "C/C++: g++.exe build active file",
            "type": "shell",
            "command": "/usr/bin/g++",
            "args": [
				        //"-std=c++17",
				        //"-fdiagnostics-color=always",
                "-static",
				        "${file}",
                "-DCURL_STATICLIB",
				        "-I/usr/lib/curl/include",
				        //"-I/tmp/curl/include",
                "/usr/lib/curl/lib/libcurl.a",
                //"/tmp/curl/lib/libcurl.a",
                "-lcares",
                "-lssh2",
                "-lssl",
                "-lcrypto",
                "-lz",
				        "-o",
				        "${fileDirname}/curlman",
                //"--verbose",
			],
            "options": {
				"cwd": "${fileDirname}"
			},
            "problemMatcher": [
				"$gcc"
			],
            "group": {
				"kind": "build",
				"isDefault": true
			},
            "detail": "compiler: /usr/bin/g++"
        }
    ]
}
```



When building with g++ only: 

```
g++ -static main.cpp -DCURL_STATICLIB -I/usr/lib/curl/include /usr/lib/curl/lib/libcurl.a -lcares -lssh2 -lssl -lcrypto -lz -o src/curlman
```













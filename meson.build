project('learning-wayland', 'cpp', 'c', default_options : ['cpp_std=c++14'])

wl_server = dependency('wayland-server')
egl = dependency('egl')
glesv2 = dependency('glesv2')
x11 = dependency('x11')
xcb = dependency('xcb')
x11_xcb = dependency('x11-xcb')

scanner = dependency('wayland-scanner')
scanner_path = scanner.get_pkgconfig_variable('wayland_scanner')

wayland_server_header = custom_target('wayland-server-header',
                                      output: 'wayland-server-protocol.h',
                                      input: '/usr/share/wayland/wayland.xml',
                                      command: [scanner_path, 'server-header' ,'@INPUT@', '@OUTPUT@'])

wayland_server_code = custom_target('wayland-server-code',
                                    output: 'wayland-server-protocol.c',
                                    input:  '/usr/share/wayland/wayland.xml',
                                    command: [scanner_path, 'code' ,'@INPUT@', '@OUTPUT@'])

xdg_shell_server_header = custom_target('xdg-shell-header',
                                        output: 'xdg-shell-server-protocol.h',
                                        input: '/usr/share/wayland-protocols/unstable/xdg-shell/xdg-shell-unstable-v6.xml',
                                        command: [scanner_path, 'server-header' ,'@INPUT@', '@OUTPUT@'])

xdg_shell_server_code = custom_target('xdg-shell-code',
                                        output: 'xdg-shell-server-protocol.c',
                                        input: '/usr/share/wayland-protocols/unstable/xdg-shell/xdg-shell-unstable-v6.xml',
                                        command: [scanner_path, 'code' ,'@INPUT@', '@OUTPUT@'])


executable('server', 'main.cpp', 'egl.cpp', 'compositor.cpp', 'shell.cpp', 'surface.cpp',
           wayland_server_header, wayland_server_code,
           xdg_shell_server_header, xdg_shell_server_code,
           dependencies : [wl_server, egl, glesv2, x11, xcb, x11_xcb])

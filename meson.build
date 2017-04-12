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

executable('server', 'main.cpp', 'egl.cpp',
           wayland_server_header, wayland_server_code,
           dependencies : [wl_server, egl, glesv2, x11, xcb, x11_xcb])

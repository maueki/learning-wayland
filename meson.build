project('learning-wayland', 'cpp')

wl_server = dependency('wayland-server')
egl = dependency('egl')
glesv2 = dependency('glesv2')
x11 = dependency('x11')
xcb = dependency('xcb')
x11_xcb = dependency('x11-xcb')

executable('server', 'main.cpp', 'egl.cpp', dependencies : [wl_server, egl, glesv2, x11, xcb, x11_xcb])

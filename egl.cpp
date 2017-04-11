#include <X11/Xlib.h>
#include <X11/Xlib-xcb.h>
#include <xcb/xcb.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <cstdio>
#include <cassert>

bool egl_init(wl_display* wl_disp) {

    assert(wl_disp);

    Display* display = XOpenDisplay(NULL);
    assert(display);

    xcb_connection_t* conn = XGetXCBConnection(display);
    assert(conn);

    xcb_screen_t* screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
    assert(screen);

    xcb_window_t window = xcb_generate_id(conn);

    xcb_create_window(
        conn, XCB_COPY_FROM_PARENT, window, screen->root, 0, 0,  // x, y
        1024, 768,  // width, height
        10,         // border width
        XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, NULL);

    xcb_map_window(conn, window);

    xcb_flush(conn);

    auto get_platform_display =
        reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(
            eglGetProcAddress("eglGetPlatformDisplayEXT"));
    assert (get_platform_display);

    EGLDisplay egl_display =
        get_platform_display(EGL_PLATFORM_X11_KHR, display, NULL);
    assert(egl_display != EGL_NO_DISPLAY);

    EGLint major, minor;
    auto egl_init_ret = eglInitialize(egl_display, &major, &minor);
    assert(egl_init_ret);

    auto bind_display = reinterpret_cast<PFNEGLBINDWAYLANDDISPLAYWL>(
        eglGetProcAddress("eglBindWaylandDisplayWL"));
    assert(bind_display);

    bind_display(egl_display, wl_disp);

    return true;
}


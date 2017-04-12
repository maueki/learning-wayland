#include <cstdio>
#include <cstdlib>
#include <error.h>
#include <cassert>
#include <memory>
#include <wayland-server.h>

#include "compositor.h"

bool egl_init(wl_display* wl_disp);

int main(int argc, char *argv[])
{
    wl_display* display = wl_display_create();

    auto egl_init_ret = egl_init(display);
    assert(egl_init_ret);

    const char* socket_name = wl_display_add_socket_auto(display);
    assert(socket_name);

    auto compositor = std::make_unique<Compositor>(display);

    printf("hello, wayland\n");
    wl_display_run(display);

    return 0;
}

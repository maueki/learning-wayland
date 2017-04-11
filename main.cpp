#include <cstdio>
#include <cstdlib>
#include <error.h>
#include <cassert>
#include <wayland-server.h>

int main(int argc, char *argv[])
{
    wl_display* display = wl_display_create();

    const char* socket_name = wl_display_add_socket_auto(display);
    assert(socket_name);

    printf("hello, wayland\n");
    wl_display_run(display);

    return 0;
}

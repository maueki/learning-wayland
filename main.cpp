#include <cstdio>
#include <wayland-server.h>

int main(int argc, char *argv[])
{
    wl_display* display = wl_display_create();

    printf("hello, wayland\n");
    wl_display_run(display);

    return 0;
}

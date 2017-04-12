#include "shell.h"

#include <xdg-shell-server-protocol.h>
#include <cassert>
#include <cstdio>

static struct zxdg_shell_v6_interface shell_interface = {
    &Shell::destroy, &Shell::create_positioner, &Shell::get_xdg_surface,
    &Shell::pong};

Shell::Shell(wl_display* display)
    : display_(display) {
    wl_global_create(display_, &zxdg_shell_v6_interface, 1, this,
                     &Shell::global_bind);
}

void Shell::global_bind(wl_client* client, void* data, uint32_t version,
                        uint32_t id) {
    wl_resource* resource =
        wl_resource_create(client, &zxdg_shell_v6_interface, version, id);
    assert(resource);

    auto self = static_cast<Shell*>(data);
    wl_resource_set_implementation(resource, &shell_interface, self, nullptr);
}

void Shell::destroy(struct wl_client* client, wl_resource* resource) {
    fprintf(stderr, "Shell::destroy not implemented\n");
}

void Shell::create_positioner(wl_client* client, wl_resource* resource,
                              uint32_t id) {
    fprintf(stderr, "Shell::create_positioner not implemented\n");
}

void Shell::get_xdg_surface(wl_client* client, wl_resource* resource,
                            uint32_t id, wl_resource* surface) {
    fprintf(stderr, "Shell::get_xdg_surface not implemented\n");
}

void Shell::pong(wl_client* client, wl_resource* resource, uint32_t serial) {
    fprintf(stderr, "Shell::create_positioner not implemented\n");
}

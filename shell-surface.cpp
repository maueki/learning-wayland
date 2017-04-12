#include "shell-surface.h"
#include "toplevel.h"

#include <xdg-shell-server-protocol.h>
#include <cassert>
#include <cstdio>

static struct zxdg_surface_v6_interface shell_surface_interface = {
    &ShellSurface::destroy, &ShellSurface::get_toplevel,
    &ShellSurface::get_popup, &ShellSurface::set_window_geometry,
    &ShellSurface::ack_configure};

static void destroy_shell_surface(wl_resource* resource) {
    auto surface =
        static_cast<ShellSurface*>(wl_resource_get_user_data(resource));
    delete surface;
}

ShellSurface::ShellSurface(wl_client* client, uint32_t id) {
    wl_resource* resource =
        wl_resource_create(client, &zxdg_surface_v6_interface, 1, id);
    assert(resource);

    wl_resource_set_implementation(resource, &shell_surface_interface, this,
                                   &destroy_shell_surface);
}

void ShellSurface::destroy(wl_client* client, wl_resource* resource) {
    fprintf(stderr, "ShellSurface::destroy not implemented\n");
}

void ShellSurface::get_toplevel(struct wl_client* client,
                                struct wl_resource* resource, uint32_t id) {
    auto toplevel = new Toplevel(client, id);
    assert(toplevel);
}

void ShellSurface::get_popup(wl_client* client, wl_resource* resource,
                             uint32_t id, wl_resource* parent,
                             wl_resource* positioner) {
    fprintf(stderr, "ShellSurface::get_popup not implemented\n");
}

void ShellSurface::set_window_geometry(wl_client* client, wl_resource* resource,
                                       int32_t x, int32_t y, int32_t width,
                                       int32_t height) {
    fprintf(stderr, "ShellSurface::set_window_geometry not implemented\n");
}

void ShellSurface::ack_configure(wl_client* client, wl_resource* resource,
                                 uint32_t serial) {
    fprintf(stderr, "ShellSurface::ack_configure not implemented\n");
}

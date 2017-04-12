#include "toplevel.h"

#include <xdg-shell-server-protocol.h>
#include <cassert>
#include <cstdio>

static struct zxdg_toplevel_v6_interface toplevel_interface = {
    &Toplevel::destroy,          &Toplevel::set_parent,
    &Toplevel::set_title,        &Toplevel::set_app_id,
    &Toplevel::show_window_menu, &Toplevel::move,
    &Toplevel::resize,           &Toplevel::set_max_size,
    &Toplevel::set_min_size,     &Toplevel::set_maximized,
    &Toplevel::unset_maximized,  &Toplevel::set_fullscreen,
    &Toplevel::set_minimized};

static void destroy_toplevel(wl_resource *resource) {
    auto toplevel =
        static_cast<Toplevel *>(wl_resource_get_user_data(resource));
    delete toplevel;
}

Toplevel::Toplevel(wl_client *client, uint32_t id) {
    wl_resource *resource =
        wl_resource_create(client, &zxdg_toplevel_v6_interface, 1, id);
    assert(resource);

    wl_resource_set_implementation(resource, &toplevel_interface, this,
                                   &destroy_toplevel);
}

void Toplevel::destroy(wl_client *client, wl_resource *resource) {
    fprintf(stderr, "Toplevel::destroy not implemented\n");
}

void Toplevel::set_parent(wl_client *client, wl_resource *resource,
                          wl_resource *parent) {
    fprintf(stderr, "Toplevel::set_parent not implemented\n");
}

void Toplevel::set_title(wl_client *client, wl_resource *resource,
                         const char *title) {
    fprintf(stderr, "Toplevel::set_title not implemented\n");
}

void Toplevel::set_app_id(wl_client *client, wl_resource *resource, const char *app_id) {
    fprintf(stderr, "Toplevel::set_app_id not implemented\n");
}

void Toplevel::show_window_menu(wl_client *client, wl_resource *resource,
                      wl_resource *seat, uint32_t serial, int32_t x,
                      int32_t y) {
    fprintf(stderr, "Toplevel::show_window_menu not implemented\n");
}

void Toplevel::move(wl_client *client, wl_resource *resource, wl_resource *seat,
          uint32_t serial) {
    fprintf(stderr, "Toplevel::move not implemented\n");
}

void Toplevel::resize(wl_client *client, wl_resource *resource, wl_resource *seat,
            uint32_t serial, uint32_t edges) {
    fprintf(stderr, "Toplevel::resize not implemented\n");
}

void Toplevel::set_max_size(wl_client *client, wl_resource *resource, int32_t width,
                  int32_t height) {
    fprintf(stderr, "Toplevel::set_max_size not implemented\n");
}

void Toplevel::set_min_size(wl_client *client, wl_resource *resource, int32_t width,
                  int32_t height) {
    fprintf(stderr, "Toplevel::set_min_size not implemented\n");
}

void Toplevel::set_maximized(wl_client *client, wl_resource *resource) {
    fprintf(stderr, "Toplevel::se_maximized not implemented\n");
}

void Toplevel::unset_maximized(wl_client *client, wl_resource *resource) {
    fprintf(stderr, "Toplevel::unset_miximized not implemented\n");
}

void Toplevel::set_fullscreen(wl_client *client, wl_resource *resource,
                    wl_resource *output) {
    fprintf(stderr, "Toplevel::set_fullscreen not implemented\n");
}

void Toplevel::set_minimized(wl_client *client, wl_resource *resource) {
    fprintf(stderr, "Toplevel::set_minimized not implemented\n");
}

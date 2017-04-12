#pragma once

#include <wayland-server.h>

class Shell {
    wl_display* display_;

public:
    Shell(wl_display* display);

    static void global_bind(wl_client* client, void* data, uint32_t version,
                            uint32_t id);

    static void destroy(struct wl_client* client, wl_resource* resource);

    static void create_positioner(wl_client* client, wl_resource* resource,
                                  uint32_t id);

    static void get_xdg_surface(wl_client* client, wl_resource* resource,
                                uint32_t id, wl_resource* surface);

    static void pong(wl_client* client, wl_resource* resource, uint32_t serial);
};

#pragma once

#include <wayland-server.h>

class Compositor {
    wl_display* display_;

public:
    Compositor(wl_display* display);

    static void global_bind(wl_client* client, void* data, uint32_t version,
                            uint32_t id);

    static void create_surface(wl_client* client, wl_resource* resource,
                               uint32_t id);

    static void create_region(struct wl_client* client,
                              struct wl_resource* resource, uint32_t id);
};

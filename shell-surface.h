#pragma once

#include <wayland-server.h>

class ShellSurface {
public:
    ShellSurface(wl_client* client, uint32_t id);

    static void destroy(wl_client* client, wl_resource* resource);

    static void get_toplevel(wl_client* client, wl_resource* resource,
                             uint32_t id);

    static void get_popup(wl_client* client, wl_resource* resource, uint32_t id,
                          wl_resource* parent, wl_resource* positioner);

    static void set_window_geometry(wl_client* client, wl_resource* resource,
                                    int32_t x, int32_t y, int32_t width,
                                    int32_t height);

    static void ack_configure(wl_client* client, wl_resource* resource,
                              uint32_t serial);
};

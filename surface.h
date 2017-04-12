#pragma once

#include <wayland-server.h>

class Surface {
public:
    Surface(wl_client *client, uint32_t id);

    static void destroy(wl_client *client, wl_resource *resource);

    static void attach(wl_client *client, wl_resource *resource,
                       wl_resource *buffer, int32_t x, int32_t y);

    static void damage(wl_client *client, wl_resource *resource, int32_t x,
                       int32_t y, int32_t width, int32_t height);

    static void frame(wl_client *client, wl_resource *resource,
                      uint32_t callback);

    static void set_opaque_region(wl_client *client, wl_resource *resource,
                                  wl_resource *region);

    static void set_input_region(wl_client *client, wl_resource *resource,
                                 wl_resource *region);

    static void commit(wl_client *client, wl_resource *resource);

    static void set_buffer_transform(wl_client *client, wl_resource *resource,
                                     int32_t transform);

    static void set_buffer_scale(wl_client *client, wl_resource *resource,
                                 int32_t scale);

    static void damage_buffer(wl_client *client, wl_resource *resource,
                              int32_t x, int32_t y, int32_t width,
                              int32_t height);
};

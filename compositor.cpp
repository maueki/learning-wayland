
#include "compositor.h"
#include "surface.h"
#include <wayland-server-protocol.h>
#include <cassert>
#include <cstdio>

static struct wl_compositor_interface compositor_interface = {
    &Compositor::create_surface, &Compositor::create_region};

Compositor::Compositor(wl_display* display)
    : display_(display) {
    wl_global_create(display_, &wl_compositor_interface, 4, this,
                     &Compositor::global_bind);
}

void Compositor::global_bind(wl_client* client, void* data, uint32_t version,
                             uint32_t id) {
    wl_resource* resource =
        wl_resource_create(client, &wl_compositor_interface, version, id);
    assert(resource);

    auto self = static_cast<Compositor*>(data);
    wl_resource_set_implementation(resource, &compositor_interface, self,
                                   nullptr);
}

void Compositor::create_surface(wl_client* client, wl_resource* resource,
                                uint32_t id) {
    auto surface = new Surface(client, id);
    assert(surface);
}

void Compositor::create_region(struct wl_client* client,
                               struct wl_resource* resource, uint32_t id) {
    fprintf(stderr, "Compositor::create_region not implemented\n");
}

#include "surface.h"

#include <cassert>
#include <cstdio>

static struct wl_surface_interface surface_interface = {
    &Surface::destroy,           &Surface::attach,
    &Surface::damage,            &Surface::frame,
    &Surface::set_opaque_region, &Surface::set_input_region,
    &Surface::commit,            &Surface::set_buffer_transform,
    &Surface::set_buffer_scale,  &Surface::damage_buffer};

static void destroy_surface(wl_resource *resource) {
    auto surface = static_cast<Surface *>(wl_resource_get_user_data(resource));
    delete surface;
}

Surface::Surface(wl_client *client, uint32_t id) {
    wl_resource *resource =
        wl_resource_create(client, &wl_surface_interface, 4, id);
    assert(resource);

    wl_resource_set_implementation(resource, &surface_interface, this,
                                   &destroy_surface);
}

void Surface::destroy(wl_client *client, wl_resource *resource) {
    fprintf(stderr, "Surface::destroy not implemented\n");
}

void Surface::attach(wl_client *client, wl_resource *resource,
                     wl_resource *buffer, int32_t x, int32_t y) {
    fprintf(stderr, "Surface::attach not implemented\n");
}

void Surface::damage(wl_client *client, wl_resource *resource, int32_t x,
                     int32_t y, int32_t width, int32_t height) {
    fprintf(stderr, "Surface::damage not implemented\n");
}

void Surface::frame(wl_client *client, wl_resource *resource,
                    uint32_t callback) {
    fprintf(stderr, "Surface::frame not implemented\n");
}

void Surface::set_opaque_region(wl_client *client, wl_resource *resource,
                                wl_resource *region) {
    fprintf(stderr, "Surface::set_opaque_region not implemented\n");
}

void Surface::set_input_region(wl_client *client, wl_resource *resource,
                               wl_resource *region) {
    fprintf(stderr, "Surface::set_input_region not implemented\n");
}

void Surface::commit(wl_client *client, wl_resource *resource) {
    fprintf(stderr, "Surface::commit not implemented\n");
}

void Surface::set_buffer_transform(wl_client *client, wl_resource *resource,
                                   int32_t transform) {
    fprintf(stderr, "Surface::set_buffer_transform not implemented\n");
}

void Surface::set_buffer_scale(wl_client *client, wl_resource *resource,
                               int32_t scale) {
    fprintf(stderr, "Surface::set_buffer_scale not implemented\n");
}

void Surface::damage_buffer(wl_client *client, wl_resource *resource, int32_t x,
                            int32_t y, int32_t width, int32_t height) {
    fprintf(stderr, "Surface::damage_buffer not implemented\n");
}

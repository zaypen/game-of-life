#include "Camera.h"

Camera::Camera(const sf::Vector2f& size) : size(size), view(sf::Vector2f(size.x / 2, size.y / 2), size), scale(1.f),
                                           minScale(1.f) {}

void Camera::fit(const sf::Vector2f& size, bool keepScale) {
    minScale = minimumScale(size);
    scale = keepScale ? std::max(scale, minScale) : minScale;
    view.reset(sf::FloatRect(sf::Vector2f((this->size.x - size.x / scale) / 2, (this->size.y - size.y / scale) / 2),
                             sf::Vector2f(size.x, size.y) / scale));
}

float Camera::minimumScale(const sf::Vector2f& size) {
    auto hScale = size.x / this->size.x, vScale = size.y / this->size.y;
    return std::min(hScale, vScale);
}

void Camera::move(const sf::Vector2f& offset) {
    view.move(offset / scale);
}

void Camera::zoom(float ds) {
    auto size = view.getSize() * scale;
    scale = std::max(scale + ds, minScale);
    view.setSize(size / scale);
}

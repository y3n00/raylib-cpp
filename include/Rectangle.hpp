#ifndef RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
#define RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_

#include "./Vector2.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Rectangle type
 */
class Rectangle : public ::Rectangle {
public:
    constexpr Rectangle(const ::Rectangle& rect) noexcept : ::Rectangle{rect.x, rect.y, rect.width, rect.height} {}

    constexpr Rectangle(float x = 0, float y = 0, float width = 0, float height = 0) noexcept
        : ::Rectangle{x, y, width, height} {}

    constexpr Rectangle(::Vector2 position, ::Vector2 size) noexcept
        : ::Rectangle{position.x, position.y, size.x, size.y} {}
    constexpr Rectangle(::Vector2 size) noexcept : ::Rectangle{0, 0, size.x, size.y} {}
    constexpr Rectangle(::Vector4 rect) noexcept : ::Rectangle{rect.x, rect.y, rect.z, rect.w} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Width, width)
    GETTERSETTER(float, Height, height)

    Rectangle& operator=(const ::Rectangle& rect) {
        set(rect);
        return *this;
    }

    constexpr ::Vector4 ToVector4() const noexcept { return {x, y, width, height}; }

    constexpr operator ::Vector4() const noexcept { return ToVector4(); }

    /**
     * Draw a color-filled rectangle
     */
    void Draw(::Color color) const { ::DrawRectangleRec(*this, color); }

    void Draw(::Vector2 origin, float rotation, ::Color color) const {
        ::DrawRectanglePro(*this, origin, rotation, color);
    }

    void DrawGradientV(::Color color1, ::Color color2) const {
        ::DrawRectangleGradientV(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height),
            color1,
            color2);
    }

    void DrawGradientH(::Color color1, ::Color color2) const {
        ::DrawRectangleGradientH(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height),
            color1,
            color2);
    }

    void DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) const {
        ::DrawRectangleGradientEx(*this, col1, col2, col3, col4);
    }

    void DrawLines(::Color color) const {
        ::DrawRectangleLines(
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height),
            color);
    }

    void DrawLines(::Color color, float lineThick) const { ::DrawRectangleLinesEx(*this, lineThick, color); }

    void DrawRounded(float roundness, int segments, ::Color color) const {
        ::DrawRectangleRounded(*this, roundness, segments, color);
    }

    void DrawRoundedLines(float roundness, int segments, ::Color color) const {
#if RAYLIB_VERSION_MAJOR == 5 && RAYLIB_VERSION_MINOR == 0
        ::DrawRectangleRoundedLines(*this, roundness, segments, 1.0f, color);
#else
        ::DrawRectangleRoundedLines(*this, roundness, segments, color);
#endif
    }

    void DrawRoundedLines(float roundness, int segments, float lineThick, ::Color color) const {
#if RAYLIB_VERSION_MAJOR == 5 && RAYLIB_VERSION_MINOR == 0
        ::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
#else
        DrawRectangleRoundedLinesEx(*this, roundness, segments, lineThick, color);
#endif
    }

    /**
     * Check collision between two rectangles
     */
    bool CheckCollision(::Rectangle rec2) const { return ::CheckCollisionRecs(*this, rec2); }

    /**
     * Get collision rectangle for two rectangles collision
     */
    ::Rectangle GetCollision(::Rectangle rec2) const { return ::GetCollisionRec(*this, rec2); }

    /**
     * Check if point is inside rectangle
     */
    bool CheckCollision(::Vector2 point) const { return ::CheckCollisionPointRec(point, *this); }

    /**
     * Check collision between circle and rectangle
     */
    bool CheckCollision(::Vector2 center, float radius) const {
        return ::CheckCollisionCircleRec(center, radius, *this);
    }

    Vector2 GetSize() const { return {width, height}; }

    constexpr Rectangle& SetSize(float newWidth, float newHeight) noexcept {
        width = newWidth;
        height = newHeight;
        return *this;
    }

    constexpr Rectangle& SetSize(const ::Vector2& size) noexcept { return SetSize(size.x, size.y); }

    Rectangle& SetShapesTexture(const ::Texture2D& texture) {
        ::SetShapesTexture(texture, *this);
        return *this;
    }

    constexpr Vector2 GetPosition() const noexcept { return {x, y}; }

    constexpr Rectangle& SetPosition(float newX, float newY) noexcept {
        x = newX;
        y = newY;
        return *this;
    }

    constexpr Rectangle& SetPosition(const ::Vector2& position) noexcept { return SetPosition(position.x, position.y); }
protected:
    constexpr void set(const ::Rectangle& rect) noexcept {
        x = rect.x;
        y = rect.y;
        width = rect.width;
        height = rect.height;
    }
};
} // namespace raylib

using RRectangle = raylib::Rectangle;

#endif // RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_

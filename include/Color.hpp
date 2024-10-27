#ifndef RAYLIB_CPP_INCLUDE_COLOR_HPP_
#define RAYLIB_CPP_INCLUDE_COLOR_HPP_

#include <string>

#include "./Vector4.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * Color type, RGBA (32bit)
 */
class Color : public ::Color {
public:
    constexpr Color(const ::Color& color) noexcept : ::Color{color.r, color.g, color.b, color.a} {}

    constexpr Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255) noexcept
        : ::Color{red, green, blue, alpha} {};

    /**
     * Black.
     */
    constexpr Color() noexcept : ::Color{0, 0, 0, 255} {};

    /**
     * Returns a Color from HSV values
     */
    Color(::Vector3 hsv) { set(::ColorFromHSV(hsv.x, hsv.y, hsv.z)); }

    /**
     * Returns a Color from HSV values
     */
    static ::Color FromHSV(float hue, float saturation, float value) { return ::ColorFromHSV(hue, saturation, value); }

    /**
     * Get Color structure from hexadecimal value
     */
    Color(unsigned int hexValue) { set(::GetColor(hexValue)); }

    Color(void* srcPtr, int format) { set(::GetPixelColor(srcPtr, format)); }

    /**
     * Returns hexadecimal value for a Color
     */
    int ToInt() const { return ::ColorToInt(*this); }

    /**
     * Returns hexadecimal value for a Color
     */
    operator int() const { return ::ColorToInt(*this); }

    std::string ToString() const { return TextFormat("Color(%d, %d, %d, %d)", r, g, b, a); }

    operator std::string() const { return ToString(); }

    /**
     * Returns color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    Color Fade(float alpha) const { return ::Fade(*this, alpha); }

    /**
     * Returns Color normalized as float [0..1]
     */
    Vector4 Normalize() const { return ::ColorNormalize(*this); }

    /**
     * Returns Color from normalized values [0..1]
     */
    Color(::Vector4 normalized) { set(::ColorFromNormalized(normalized)); }

    /**
     * Returns HSV values for a Color
     */
    Vector3 ToHSV() const { return ::ColorToHSV(*this); }

    GETTERSETTER(unsigned char, R, r)
    GETTERSETTER(unsigned char, G, g)
    GETTERSETTER(unsigned char, B, b)
    GETTERSETTER(unsigned char, A, a)

    Color& operator=(const ::Color& color) {
        set(color);
        return *this;
    }

    /**
     * Set background color (framebuffer clear color)
     */
    Color& ClearBackground() {
        ::ClearBackground(*this);
        return *this;
    }

    void DrawPixel(int x, int y) const { ::DrawPixel(x, y, *this); }

    /**
     * Draw a pixel
     */
    void DrawPixel(::Vector2 pos) const { ::DrawPixelV(pos, *this); }

    /**
     * Draw a line
     */
    void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY) const {
        ::DrawLine(startPosX, startPosY, endPosX, endPosY, *this);
    }

    /**
     * Draw a line using Vector points
     */
    void DrawLine(::Vector2 startPos, ::Vector2 endPos) const { ::DrawLineV(startPos, endPos, *this); }

    /**
     * Draw a line using Vector points, with a given thickness
     */
    void DrawLine(::Vector2 startPos, ::Vector2 endPos, float thick) const {
        ::DrawLineEx(startPos, endPos, thick, *this);
    }

    void DrawLineBezier(::Vector2 startPos, ::Vector2 endPos, float thick = 1.0f) const {
        ::DrawLineBezier(startPos, endPos, thick, *this);
    }

    void DrawLineStrip(::Vector2* points, int numPoints) const { ::DrawLineStrip(points, numPoints, *this); }

    void DrawText(const char* text, int posX = 0, int posY = 0, int fontSize = 10.0f) const {
        ::DrawText(text, posX, posY, fontSize, *this);
    }

    void DrawText(const std::string& text, int posX = 0, int posY = 0, int fontSize = 10.0f) const {
        ::DrawText(text.c_str(), posX, posY, fontSize, *this);
    }

    void DrawText(const ::Font& font, const char* text, ::Vector2 position, float fontSize, float spacing) const {
        ::DrawTextEx(font, text, position, fontSize, spacing, *this);
    }

    void
    DrawText(const ::Font& font, const std::string& text, ::Vector2 position, float fontSize, float spacing) const {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, *this);
    }

    void DrawText(
        const ::Font& font,
        const char* text,
        ::Vector2 position,
        ::Vector2 origin,
        float rotation,
        float fontSize,
        float spacing) const {
        ::DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, *this);
    }

    void DrawText(
        const ::Font& font,
        const std::string& text,
        ::Vector2 position,
        ::Vector2 origin,
        float rotation,
        float fontSize,
        float spacing) const {
        ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, *this);
    }

    void DrawRectangle(int posX, int posY, int width, int height) const {
        ::DrawRectangle(posX, posY, width, height, *this);
    }

    void DrawRectangle(::Vector2 position, ::Vector2 size) const { ::DrawRectangleV(position, size, *this); }

    void DrawRectangle(::Rectangle rec) const { ::DrawRectangleRec(rec, *this); }

    void DrawRectangle(::Rectangle rec, ::Vector2 origin, float rotation) const {
        ::DrawRectanglePro(rec, origin, rotation, *this);
    }

    void DrawRectangleLines(int posX, int posY, int width, int height) const {
        ::DrawRectangleLines(posX, posY, width, height, *this);
    }

    void DrawRectangleLines(::Rectangle rec, float lineThick) const { ::DrawRectangleLinesEx(rec, lineThick, *this); }

    /**
     * Get color multiplied with another color
     */
    inline ::Color Tint(::Color tint) noexcept { return ::ColorTint(*this, tint); }

    /**
     * Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
     */
    inline ::Color Brightness(float factor) noexcept { return ::ColorBrightness(*this, factor); }

    /**
     * Get color with contrast correction, contrast values between -1.0f and 1.0f
     */
    inline ::Color Contrast(float contrast) noexcept { return ::ColorContrast(*this, contrast); }

    /**
     * Returns color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    inline ::Color Alpha(float alpha) const noexcept { return ::ColorAlpha(*this, alpha); }

    /**
     * Returns src alpha-blended into dst color with tint
     */
    inline ::Color AlphaBlend(::Color dst, ::Color tint) const noexcept { return ::ColorAlphaBlend(dst, *this, tint); }

    inline constexpr static ::Color LightGray() noexcept { return LIGHTGRAY; }
    inline constexpr static ::Color Gray() noexcept { return GRAY; }
    inline constexpr static ::Color DarkGray() noexcept { return DARKGRAY; }
    inline constexpr static ::Color Yellow() noexcept { return YELLOW; }
    inline constexpr static ::Color Gold() noexcept { return GOLD; }
    inline constexpr static ::Color Orange() noexcept { return ORANGE; }
    inline constexpr static ::Color Pink() noexcept { return PINK; }
    inline constexpr static ::Color Red() noexcept { return RED; }
    inline constexpr static ::Color Maroon() noexcept { return MAROON; }
    inline constexpr static ::Color Green() noexcept { return GREEN; }
    inline constexpr static ::Color Lime() noexcept { return LIME; }
    inline constexpr static ::Color DarkGreen() noexcept { return DARKGREEN; }
    inline constexpr static ::Color SkyBlue() noexcept { return SKYBLUE; }
    inline constexpr static ::Color Blue() noexcept { return BLUE; }
    inline constexpr static ::Color DarkBlue() noexcept { return DARKBLUE; }
    inline constexpr static ::Color Purple() noexcept { return PURPLE; }
    inline constexpr static ::Color Violet() noexcept { return VIOLET; }
    inline constexpr static ::Color DarkPurple() noexcept { return DARKPURPLE; }
    inline constexpr static ::Color Beige() noexcept { return BEIGE; }
    inline constexpr static ::Color Brown() noexcept { return BROWN; }
    inline constexpr static ::Color DarkBrown() noexcept { return DARKBROWN; }
    inline constexpr static ::Color White() noexcept { return WHITE; }
    inline constexpr static ::Color Black() noexcept { return BLACK; }
    inline constexpr static ::Color Blank() noexcept { return BLANK; }
    inline constexpr static ::Color Magenta() noexcept { return MAGENTA; }
    inline constexpr static ::Color RayWhite() noexcept { return RAYWHITE; }
protected:
    inline constexpr void set(const ::Color& color) noexcept {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }
};

} // namespace raylib

using RColor = raylib::Color;

#endif // RAYLIB_CPP_INCLUDE_COLOR_HPP_

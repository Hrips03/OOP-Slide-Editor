struct Shape
{
    enum class ShapeType
    {
        Circle,
        Rectangle,
        Triangle
    };

    struct Geometry
    {
        int x;
        int y;
        int size;
    };

    enum class Attributes
    {
        Color,
        OutlineColor
    };
};
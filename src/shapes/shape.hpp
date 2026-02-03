#ifndef GYZOA_SHAPE_HPP
#define GYZOA_SHAPE_HPP

namespace gyoza
{

struct Shape
{
    Shape() = default;
    Shape(const Shape& other) = default;
    Shape(Shape&& other) = default;

    unsigned int Get_id() {return shape_id;};
    unsigned int Get_data_id() {return data_component_id;};
    unsigned int Get_physic_id() {return physic_component_id;};
    unsigned int Get_render_id() {return render_component_id;};

    virtual ~Shape() = default;
protected:
    unsigned int shape_id{};
    unsigned int data_component_id{};
    unsigned int physic_component_id{};
    unsigned int render_component_id{};
};

}

#endif

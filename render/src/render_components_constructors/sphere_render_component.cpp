#include "sphere_render_component.hpp"
#include "../../../src/constants.hpp"
#include <cmath>

using namespace gyoza;

gyoza::Sphere_render_component::Sphere_render_component(float radius, unsigned int stack_amount, unsigned int sector_amount, unsigned int data_id): Render_component{data_id}
{
    float x{}, y{}, z{}, x_y{};
    float inv_radious{ 1.0f / radius };

    float sector_step = 2 * gyoza::constants::PI / sector_amount;
    float stack_step = gyoza::constants::PI / stack_amount;

    float sector_angle{}, stack_angle{};

    for(unsigned int i{}; i <= stack_amount; i++)
    {
        stack_angle = gyoza::constants::PI / 2 - i * stack_step;
        x_y = radius * std::cos(stack_angle);
        z = radius * std::sin(stack_angle);

        for(unsigned int j{}; j <= sector_amount; j++)
        {
            sector_angle = j * sector_step;

            x = x_y * std::cos(sector_angle);
            y = x_y * std::sin(sector_angle);

            Vertex tmp{};
            tmp.possition.x = x;
            tmp.possition.y = y;
            tmp.possition.z = z;

            tmp.normal.x = tmp.possition.x * inv_radious;
            tmp.normal.y = tmp.possition.y * inv_radious;
            tmp.normal.z = tmp.possition.z * inv_radious;

            tmp.tex_cords.x = j / sector_amount;
            tmp.tex_cords.y = i / stack_amount;

            this->vertices.push_back(tmp);
        }
    }

    unsigned int k1{}, k2{};
    for(unsigned int i{}; i < stack_amount; i++)
    {
        k1 = i * (sector_amount + 1);
        k2 = k1 + sector_amount + 1;

        for(unsigned int j{}; j < sector_amount; j++, k1++, k2++)
        {
            if(i != 0)
            {
                this->indices.push_back(k1);
                this->indices.push_back(k2);
                this->indices.push_back(k1 + 1);
            }

            if(i != (sector_amount - 1))
            {
                this->indices.push_back(k1 + 1);
                this->indices.push_back(k2);
                this->indices.push_back(k2 + 1);
            }
        }
    }

    Buffor_data();
}

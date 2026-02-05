#ifndef GYOZA_MAGIC_CONTAINER_HPP
#define GYOZA_MAGIC_CONTAINER_HPP

#include <vector>
#include <initializer_list>

namespace gyoza
{

template<typename T>
class Magic_container
{
public:
    Magic_container() noexcept = default;
    Magic_container(std::initializer_list<T> content) noexcept;

    Magic_container(const std::vector<T> & content) noexcept;
    Magic_container(std::vector<T> && content) noexcept;

    Magic_container(const Magic_container & other) noexcept;
    Magic_container(Magic_container && other) noexcept = default;

    Magic_container & operator=(const Magic_container & other) noexcept;
    Magic_container & operator=(Magic_container && other) noexcept = default;
    Magic_container & operator=(const std::vector<T> & content) noexcept;
    Magic_container & operator=(std::vector<T> && content) noexcept;

    T & operator[](size_t acess_id);
    const T & operator[](size_t acess_id) const;

    void Push_back(T el) noexcept;
    size_t Push_back(T && el) noexcept;

    void Erase(size_t acess_id) noexcept;

    ~Magic_container() noexcept = default;
private:
    std::vector<std::size_t> data_index{};
    std::vector<std::size_t> free_indexes{};
    std::vector<std::size_t> id{};
    std::vector<T> data{};
};

template<typename T>
Magic_container<T>::Magic_container(std::initializer_list<T> content) noexcept
{
    data_index.clear();
    id.clear();
    data.clear();

    data_index.reserve(content.size());
    id.reserve(content.size());
    data.reserve(content.size());

    for(auto && el : content)
    {
        data_index.push_back(data.size());
        id.push_back(data.size());
        data.push_back( std::move(el) );
    }
}

template<typename T>
Magic_container<T>::Magic_container(const Magic_container<T> & other) noexcept: data_index{other.data_index}, id{other.id}, data{other.data}
{

}

template<typename T>
Magic_container<T>::Magic_container(const std::vector<T> & content) noexcept
{
    data_index.clear();
    id.clear();
    data.clear();

    data_index.reserve(content.size());
    id.reserve(content.size());
    data.reserve(content.size());

    for(auto el : content)
    {
        data_index.push_back(data.size());
        id.push_back(data.size());
        data.push_back(el);
    }
}

template<typename T>
Magic_container<T>::Magic_container(std::vector<T> && content) noexcept
{
    data_index.clear();
    id.clear();
    data.clear();

    data_index.reserve(content.size());
    id.reserve(content.size());
    data.reserve(content.size());

    for(auto && el : content)
    {
        data_index.push_back(data.size());
        id.push_back(data.size());
        data.push_back( std::move(el) );
    }
}

template<typename T>
Magic_container<T> & Magic_container<T>::operator=(const Magic_container<T> & other) noexcept
{
    this->data_index = other.data_index;
    this->id = other.id;
    this->data = other.data;
    this->data.size() = other.data.size();

    return *this;
}

template<typename T>
Magic_container<T> & Magic_container<T>::operator=(const std::vector<T> & content) noexcept
{
    data_index.clear();
    id.clear();
    data.clear();

    data_index.reserve(content.size());
    id.reserve(content.size());
    data.reserve(content.size());

    for(auto el : content)
    {
        data_index.push_back(data.size());
        id.push_back(data.size());
        data.push_back(el);
    }

    return *this;
}

template<typename T>
Magic_container<T> & Magic_container<T>::operator=(std::vector<T> && content) noexcept
{
    data_index.clear();
    id.clear();
    data.clear();

    data_index.reserve(content.size());
    id.reserve(content.size());
    data.reserve(content.size());

    for(auto &&el : content)
    {
        data_index.push_back(data.size());
        id.push_back(data.size());
        data.push_back( std::move(el) );
    }

    return *this;
}

template<typename T>
T & Magic_container<T>::operator[](size_t acess_id)
{
    return data[ data_index[acess_id] ];
}

template<typename T>
const T & Magic_container<T>::operator[](size_t acess_id) const
{
    return data[ data_index[acess_id] ];
}

template<typename T>
void Magic_container<T>::Push_back(T el) noexcept
{
    return Push_back( std::move(el) );
}

template<typename T>
size_t Magic_container<T>::Push_back(T && el) noexcept
{
    std::size_t new_id{};
    std::size_t internal_index{ data.size() };

    if(!free_indexes.empty())
    {
        new_id = free_indexes.back();
        free_indexes.pop_back();
        data_index[new_id] = internal_index;
    }
    else
    {
        new_id = data_index.size();
        data_index.push_back(internal_index);
    }


    data.push_back( std::move(el) );
    id.push_back(new_id);

    return new_id;
}

template<typename T>
void Magic_container<T>::Erase(size_t acess_id) noexcept
{
    size_t real_id = data_index.at(acess_id);
    size_t last = data.size() - 1;

    if(real_id != last)
    {
        std::swap( data[real_id], data[last]  );
        std::swap( id[real_id], id[last] );

        std::size_t moved_id = id[real_id];

        data_index[moved_id] = real_id;
    }

    id.pop_back();
    data.pop_back();

    free_indexes.push_back(acess_id);
}

}

#endif // GYOZA_MAGIC_CONTAINER_HPP

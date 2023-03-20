#pragma once
//head file start with "exp" means expriment imm
namespace experiment
{
	/*before build a vector,we need build iterator
	* and we use std::allocator as our allocator
	*/
    template <class _Iterator>
    struct iterator_traits
    {
        using value_type = typename _Iterator::value_type;
        using pointer = typename _Iterator::pointer;

    };
    /*************************************
    * vector implement use std::allocator;
    *************************************/
    template<typename T>
    class vector
    {
        using value_type = T;
        using allocator_type = std::allocator<value_type>;

        using pointer = typename  allocator_type::pointer;
        using size_type = typename allocator_type::size_type;

    public:

        //constructors
        vector(const allocator_type& _alloc = allocator_type())
            :alloc(_alloc) {}

        ~vector() { free(); }

        //why we need transfor pointer to iter
        using iterator = pointer;
        iterator make_iter(pointer _ptr) { return _ptr; }

        //iterator
        iterator begin() { return make_iter(alloc.elements); }
        iterator end() { return make_iter(alloc.first_free); }
        size_type size() { return alloc.first_free - alloc.elements; }
        size_type capacity() { return alloc.cap - alloc.elements; }
        //modifier
        void push_back(const value_type& val)
        {
            chk_n_alloc();
            alloc.construct(alloc.first_free++, val);
        }
    protected:
        void chk_n_alloc()
        {
            if (size() == capacity())
                reallocate();
        }
        void reallocate()
        {
            size_type newcapacity = size() ? size() * 2 : 1;
            pointer newdata = alloc.allocate(newcapacity);

            pointer dest = newdata;
            pointer elem = alloc.elements;
            for (size_type i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            alloc.elements = newdata;
            alloc.first_free = dest;
            alloc.cap = alloc.elements + newcapacity;
        }
        void free()
        {
            if (alloc.elements)
            {

            }
        }
    private:

        struct vector_alloc :allocator_type
        {
            vector_alloc(const allocator_type& _alloc )
                :allocator_type(_alloc){}
            pointer elements = nullptr;
            pointer first_free = nullptr;
            pointer cap = nullptr;
        } alloc;
    };
}
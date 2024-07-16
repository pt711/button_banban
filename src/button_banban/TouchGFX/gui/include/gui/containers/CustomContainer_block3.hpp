#ifndef CUSTOMCONTAINER_BLOCK3_HPP
#define CUSTOMCONTAINER_BLOCK3_HPP

#include <gui_generated/containers/CustomContainer_block3Base.hpp>

class CustomContainer_block3 : public CustomContainer_block3Base
{
public:
    CustomContainer_block3();
    virtual ~CustomContainer_block3() {}

    virtual void initialize();

    int type = 1;
protected:
};

#endif // CUSTOMCONTAINER_BLOCK3_HPP

#ifndef CUSTOMCONTAINER_BLOCK1_HPP
#define CUSTOMCONTAINER_BLOCK1_HPP

#include <gui_generated/containers/CustomContainer_block1Base.hpp>

class CustomContainer_block1 : public CustomContainer_block1Base
{
public:
    CustomContainer_block1();
    virtual ~CustomContainer_block1() {}

    virtual void initialize();

    int type = 1;
protected:
};

#endif // CUSTOMCONTAINER_BLOCK1_HPP

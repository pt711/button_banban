#ifndef CUSTOMCONTAINER_BLOCK2_HPP
#define CUSTOMCONTAINER_BLOCK2_HPP

#include <gui_generated/containers/CustomContainer_block2Base.hpp>

class CustomContainer_block2 : public CustomContainer_block2Base
{
public:
    CustomContainer_block2();
    virtual ~CustomContainer_block2() {}

    virtual void initialize();

    int type = 1;
protected:
};

#endif // CUSTOMCONTAINER_BLOCK2_HPP

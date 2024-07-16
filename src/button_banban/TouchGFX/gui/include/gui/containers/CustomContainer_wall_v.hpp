#ifndef CUSTOMCONTAINER_WALL_V_HPP
#define CUSTOMCONTAINER_WALL_V_HPP

#include <gui_generated/containers/CustomContainer_wall_vBase.hpp>

class CustomContainer_wall_v : public CustomContainer_wall_vBase
{
public:
    CustomContainer_wall_v();
    virtual ~CustomContainer_wall_v() {}

    virtual void initialize();

    int type = 3;
protected:
};

#endif // CUSTOMCONTAINER_WALL_V_HPP

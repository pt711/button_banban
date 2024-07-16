#ifndef CUSTOMCONTAINER_WALL_H_HPP
#define CUSTOMCONTAINER_WALL_H_HPP

#include <gui_generated/containers/CustomContainer_wall_hBase.hpp>

class CustomContainer_wall_h : public CustomContainer_wall_hBase
{
public:
    CustomContainer_wall_h();
    virtual ~CustomContainer_wall_h() {}

    virtual void initialize();

    int type = 2;
protected:
};

#endif // CUSTOMCONTAINER_WALL_H_HPP

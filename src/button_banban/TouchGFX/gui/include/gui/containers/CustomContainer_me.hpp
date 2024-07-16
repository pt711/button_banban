#ifndef CUSTOMCONTAINER_ME_HPP
#define CUSTOMCONTAINER_ME_HPP

#include <gui_generated/containers/CustomContainer_meBase.hpp>

class CustomContainer_me : public CustomContainer_meBase
{
public:
    CustomContainer_me();
    virtual ~CustomContainer_me() {}

    virtual void initialize();
    virtual void blink();
    virtual void ticker();
protected:

};

#endif // CUSTOMCONTAINER_ME_HPP

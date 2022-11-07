#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() { res = new Resource(); };

    ~ResourceManager() { delete res; };

    double get() { return res->get(); };

    ResourceManager(const ResourceManager& manager) { res = new Resource(*manager.res); };

    ResourceManager& operator=(const ResourceManager& manager)
    {
        delete res;
        res = new Resource(*manager.res);
        return *this;
    }

    ResourceManager(ResourceManager&& manager) noexcept
    {
        res         = manager.res;
        manager.res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& manager) noexcept
    {
        delete res;
        res         = manager.res;
        manager.res = nullptr;
        return *this;
    }

private:
    Resource* res = nullptr;
};

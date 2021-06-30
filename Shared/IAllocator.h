#ifndef _I_ALLOCATOR_H_
#define _I_ALLOCATOR_H_
#pragma once

#include <cstdint>

class IAllocator 
{
private:
    static const uint32_t s_DEFAULT_ALLIGNMENT = 4;

public:
    IAllocator(void);
    virtual ~IAllocator();

    virtual void* Allocate(uint32_t size, uint32_t alignment = s_DEFAULT_ALLIGNMENT) = 0;
    virtual void Deallocate(void* ptr) = 0;

protected:
    uint32_t m_TotalAllocatedMemory;
    uint32_t m_TotalAllocations;

private:
    IAllocator(const IAllocator& allocator);
    IAllocator& operator=(const IAllocator& allocator);
};

#endif // _I_ALLOCATOR_H_
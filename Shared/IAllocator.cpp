#include "IAllocator.h"
#if _DEBUG
#include <assert.h>
#endif

IAllocator::IAllocator(void)
:   m_TotalAllocatedMemory(0),
    m_TotalAllocations(0)
{
}

IAllocator::~IAllocator()
{
#if _DEBUG
    assert(m_TotalAllocatedMemory == 0 && m_TotalAllocations == 0);
#endif
}
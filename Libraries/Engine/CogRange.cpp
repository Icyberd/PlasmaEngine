// MIT Licensed (see LICENSE.md).
#include "Precompiled.hpp"

namespace Plasma
{

//                               CogHashSetRange //

CogHashSetRange::CogHashSetRange() : CogHashSet::range()
{
}
CogHashSetRange::CogHashSetRange(const CogHashSetRange::range& rhs) : CogHashSet::range(rhs)
{
}

Cog* CogHashSetRange::Front()
{
  return CogHashSet::range::Front();
}

} // namespace Plasma
